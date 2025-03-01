#include <default-shaders.hpp>
#include <render.hpp>
#include <shadercompile.h>

#include <protocols/wayland.hpp>
#include <protocols/wlr-layer-shell-unstable-v1.hpp>
#include <wayland-client-protocol.h>
#include <wayland-client.h>

#include <args.hxx>

#include <chrono>
#include <cstdint>
#include <cstring>
#include <filesystem>
#include <iostream>
#include <memory>
#include <thread>

struct Monitor {
  std::unique_ptr<CCWlOutput> output;
  std::unique_ptr<CCWlSurface> wlSurface;
  std::unique_ptr<CCZwlrLayerSurfaceV1> wlrLayerSurface;
  std::unique_ptr<VkPaperRenderer> renderer;
  uint32_t width;
  uint32_t height;
  bool initialized;
};
static std::vector<Monitor> sMonitors;

static std::unique_ptr<CCWlCompositor> sCompositor;
static std::unique_ptr<CCZwlrLayerShellV1> sLayerShell;

static void nop() {}

static void addInterface(void *data, struct wl_registry *registry,
                         uint32_t name, const char *interface,
                         uint32_t version) {
  (void)data;
  if (strcmp(interface, wl_compositor_interface.name) == 0) {
    sCompositor = std::make_unique<CCWlCompositor>((wl_proxy *)wl_registry_bind(
        registry, name, &wl_compositor_interface, 4));
  } else if (strcmp(interface, wl_output_interface.name) == 0) {
    auto output = std::make_unique<CCWlOutput>(
        (wl_proxy *)wl_registry_bind(registry, name, &wl_output_interface, 4));
    sMonitors.push_back(
        Monitor{std::move(output), nullptr, nullptr, nullptr, 128, 128, false});
  } else if (strcmp(interface, zwlr_layer_shell_v1_interface.name) == 0) {
    sLayerShell =
        std::make_unique<CCZwlrLayerShellV1>((wl_proxy *)wl_registry_bind(
            registry, name, &zwlr_layer_shell_v1_interface, 1));
  }
}

static void removeInterface(void *data, struct wl_registry *wl_registry,
                            uint32_t name) {}

int main(int argc, char **argv) {
  args::ArgumentParser parser("vkpaper");
  args::Positional<std::filesystem::path> shaderFile{
      parser, "shader file",
      "The fragment shader (in ShaderToy compatible format) to use as your "
      "wallpaper."};
  args::HelpFlag help(parser, "help", "Display this help menu", {'h', "help"});
  args::CompletionFlag completion(parser, {"complete"});
  try {
    parser.ParseCLI(argc, argv);
  } catch (const args::Completion &e) {
    std::cout << e.what();
    return 0;
  } catch (const args::Help &) {
    std::cout << parser;
    return 0;
  } catch (const args::ParseError &e) {
    std::cerr << e.what() << std::endl;
    std::cerr << parser;
    return 1;
  }

  if (!shaderFile) {
    std::cerr << "No shader file given. Aborting...\n";
    exit(1);
  }
  if (!std::filesystem::exists(*shaderFile)) {
    std::cerr << "Shader file at " << shaderFile->string()
              << " not found. Aborting...\n";
    exit(1);
  }

  const auto outputDir = std::filesystem::path{"/tmp"} / "vkshader";
  if (!std::filesystem::exists(outputDir)) {
    std::filesystem::create_directory(outputDir);
  }

  if (!compileShaderToSpirV("default-vertex-shader", defaultVertexShader,
                            outputDir / "default.vert.spv", false)) {
    std::cerr << "Could not compile default vertex shader.\n";
    exit(1);
  }
  if (!compileShaderToSpirV("default-fragment-shader", defaultFragmentShader,
                            outputDir / "default.frag.spv", true)) {
    std::cerr << "Could not compile default fragment shader.\n";
    exit(1);
  }

  const auto spirvOutput = outputDir / "user.frag.spv";
  if (!compileShaderToySnippetToSpirVFragment(*shaderFile, spirvOutput)) {
    std::cerr << "Could not compile shader for " << shaderFile->string()
              << "\n";
  }

  auto wl = wl_display_connect(nullptr);
  auto registry = wl_display_get_registry(wl);
  struct wl_registry_listener regListener = {.global = addInterface,
                                             .global_remove = removeInterface};
  wl_registry_add_listener(registry, &regListener, nullptr);

  wl_display_dispatch(wl);
  if (wl_display_roundtrip(wl) == -1) {
    return EXIT_FAILURE;
  }

  for (auto &monitor : sMonitors) {
    monitor.wlSurface =
        std::make_unique<CCWlSurface>(sCompositor->sendCreateSurface());
    monitor.wlrLayerSurface =
        std::make_unique<CCZwlrLayerSurfaceV1>(sLayerShell->sendGetLayerSurface(
            monitor.wlSurface->resource(), monitor.output->resource(),
            ZWLR_LAYER_SHELL_V1_LAYER_BACKGROUND, "vkpaper"));

    monitor.wlrLayerSurface->sendSetSize(0, 0);
    monitor.wlrLayerSurface->sendSetAnchor(
        (zwlrLayerSurfaceV1Anchor)(ZWLR_LAYER_SURFACE_V1_ANCHOR_TOP |
                                   ZWLR_LAYER_SURFACE_V1_ANCHOR_RIGHT |
                                   ZWLR_LAYER_SURFACE_V1_ANCHOR_BOTTOM |
                                   ZWLR_LAYER_SURFACE_V1_ANCHOR_LEFT));
    monitor.wlrLayerSurface->sendSetExclusiveZone(-1);

    monitor.wlrLayerSurface->setConfigure([&monitor](CCZwlrLayerSurfaceV1 *r,
                                                     uint32_t serial,
                                                     uint32_t x, uint32_t y) {
      std::cout << "configuring monitor with serial " << serial << "..."
                << "\n";
      r->sendAckConfigure(serial);

      monitor.initialized = true;
    });

    monitor.wlSurface->sendCommit();
  }

  // this is necessary to trigger layer_surface configure before we attach to
  // the surface via vulkan
  if (wl_display_dispatch(wl) == -1) {
    std::cerr << "Initial wl_display_dispatch failed!" << "\n";
  }

  for (auto &monitor : sMonitors) {
    monitor.renderer = std::make_unique<VkPaperRenderer>(
        wl, (wl_surface *)monitor.wlSurface->resource());
  }

  const auto programStartTime = std::chrono::system_clock::now();
  int frameNumber = 0;

  do {
    const auto timeSinceStart =
        std::chrono::system_clock::now() - programStartTime;
    const auto timeSinceStartFloat =
        std::chrono::duration_cast<std::chrono::milliseconds>(timeSinceStart)
            .count() /
        1000.0f;
    const auto currentUniforms = UniformBuffer{
        timeSinceStartFloat, 0.0f, 60.0f, frameNumber++, Vec4{10, 10, 0, 0},
        Vec3{1920, 1080, 0},
    };

    const auto renderStart = std::chrono::system_clock::now();
    for (const auto &monitor : sMonitors) {
      monitor.renderer->updateUniformBuffer(currentUniforms);
      monitor.renderer->drawFrame();
    }
    const auto renderEnd = std::chrono::system_clock::now();
    const auto duration = renderEnd - renderStart;
    const auto sleepDuration = std::chrono::milliseconds{16} -
                               duration; // todo: ensure this is positive
    const auto durationUs =
        std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
    const auto sleepTimeUs =
        std::chrono::duration_cast<std::chrono::microseconds>(sleepDuration)
            .count();
    // std::cout << "rendered vkpaper frame in " << durationUs / 1000.0f
    //           << "ms, sleeping for " << sleepTimeUs / 1000.0f
    //           << "ms, elapsed time: " << timeSinceStartFloat << "s"
    //           << "\n";

    std::this_thread::sleep_for(sleepDuration);
  } while (wl_display_dispatch(wl) != -1);
}
