#include <DefaultShaders.hpp>
#include <FileUtils.hpp>
#include <ShaderCompile.hpp>
#include <Socket.hpp>
#include <VkPaperRenderer.hpp>

#include <atomic>
#include <mutex>
#include <protocols/wayland.hpp>
#include <protocols/wlr-layer-shell-unstable-v1.hpp>

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
  uint32_t wlName;

  std::unique_ptr<VkPaperRenderer> renderer;
  std::atomic_bool needsShaderReload;
  std::string name;
  uint32_t width;
  uint32_t height;
  bool initialized;

  void registerListeners() {
    output->setName([this](CCWlOutput *, const char *name_) {
      std::cout << "Monitor connected: " << name_ << std::endl;
      name = std::string{name_};
    });

    output->setMode([this](CCWlOutput *, uint32_t flags_, int32_t width_,
                           int32_t height_, int32_t refresh_) {
      std::cout << "Monitor " << name << " resized to " << width_ << "x"
                << height_ << "\n";
      width = width_;
      height = height_;
    });
  }
};

static std::mutex sMonitorMutex;
static std::vector<std::unique_ptr<Monitor>> sMonitors;

static std::unique_ptr<CCWlCompositor> sCompositor;
static std::unique_ptr<CCZwlrLayerShellV1> sLayerShell;

static std::filesystem::path sCurrentShaderFile;

const auto outputDir = std::filesystem::path{"/tmp"} / "vkshader";
const auto spirvUserOutput = outputDir / "user.frag.spv";

static void nop() {}

static void addInterface(CCWlRegistry *registry, uint32_t name,
                         const char *interface, uint32_t version) {
  if (strcmp(interface, wl_compositor_interface.name) == 0) {
    sCompositor = std::make_unique<CCWlCompositor>(
        (wl_proxy *)wl_registry_bind((wl_registry *)registry->resource(), name,
                                     &wl_compositor_interface, 4));
  } else if (strcmp(interface, wl_output_interface.name) == 0) {
    auto output = std::make_unique<CCWlOutput>((wl_proxy *)wl_registry_bind(
        (wl_registry *)registry->resource(), name, &wl_output_interface, 4));
    auto monitor =
        std::make_unique<Monitor>(std::move(output), nullptr, nullptr, name,
                                  nullptr, true, "", 0, 0, false);
    monitor->registerListeners();

    std::lock_guard lock{sMonitorMutex};
    sMonitors.push_back(std::move(monitor));
  } else if (strcmp(interface, zwlr_layer_shell_v1_interface.name) == 0) {
    sLayerShell = std::make_unique<CCZwlrLayerShellV1>(
        (wl_proxy *)wl_registry_bind((wl_registry *)registry->resource(), name,
                                     &zwlr_layer_shell_v1_interface, 1));
  }
}

static void removeInterface(CCWlRegistry *registry, uint32_t name) {
  std::lock_guard lock{sMonitorMutex};
  for (auto &monitor : sMonitors) {
    if (monitor->wlName == name) {
      std::cout << "Monitor " << monitor->name << " was removed.\n";
      std::erase(sMonitors, monitor);
      return;
    }
  }
}

void checkAndCreateLayerSurfaces(wl_display *wl_display) {
  for (auto &monitor : sMonitors) {
    if (monitor->wlSurface == nullptr) {
      monitor->wlSurface =
          std::make_unique<CCWlSurface>(sCompositor->sendCreateSurface());
      monitor->wlrLayerSurface = std::make_unique<CCZwlrLayerSurfaceV1>(
          sLayerShell->sendGetLayerSurface(
              monitor->wlSurface->resource(), monitor->output->resource(),
              ZWLR_LAYER_SHELL_V1_LAYER_BACKGROUND, "vkpaper"));

      monitor->wlrLayerSurface->sendSetSize(0, 0);
      monitor->wlrLayerSurface->sendSetAnchor(
          (zwlrLayerSurfaceV1Anchor)(ZWLR_LAYER_SURFACE_V1_ANCHOR_TOP |
                                     ZWLR_LAYER_SURFACE_V1_ANCHOR_RIGHT |
                                     ZWLR_LAYER_SURFACE_V1_ANCHOR_BOTTOM |
                                     ZWLR_LAYER_SURFACE_V1_ANCHOR_LEFT));
      monitor->wlrLayerSurface->sendSetExclusiveZone(-1);

      monitor->wlrLayerSurface->setConfigure(
          [&monitor](CCZwlrLayerSurfaceV1 *r, uint32_t serial, uint32_t x,
                     uint32_t y) {
            // std::cout << "Configuring layer surface for monitor "
            //           << monitor->name << "...\n";
            r->sendAckConfigure(serial);

            monitor->initialized = true;
          });

      monitor->wlSurface->sendCommit();
      wl_display_flush(wl_display);
    }
  }
}

int main(int argc, char **argv) {
  args::ArgumentParser parser("vkpaper");
  args::Positional<std::filesystem::path> shaderFile{
      parser, "shader file",
      "The fragment shader (in Shadertoy compatible format) to use as your "
      "wallpaper."};
  args::ValueFlag<std::string> iChannel0{parser,
                                         "iChannel0",
                                         "Input image to use as iChannel0",
                                         {'0', "iChannel0"}};
  args::ValueFlag<std::string> iChannel1{parser,
                                         "iChannel1",
                                         "Input image to use as iChannel1",
                                         {'1', "iChannel1"}};
  args::ValueFlag<std::string> iChannel2{parser,
                                         "iChannel2",
                                         "Input image to use as iChannel2",
                                         {'2', "iChannel2"}};
  args::ValueFlag<std::string> iChannel3{parser,
                                         "iChannel3",
                                         "Input image to use as iChannel3",
                                         {'3', "iChannel3"}};
  args::HelpFlag help(parser, "help", "Display this help menu", {'h', "help"});

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
  sCurrentShaderFile = *shaderFile;

  auto wlDisplay = wl_display_connect(nullptr);
  auto registry = std::make_unique<CCWlRegistry>(
      (wl_proxy *)wl_display_get_registry(wlDisplay));
  registry->setGlobal(addInterface);
  registry->setGlobalRemove(removeInterface);

  if (wl_display_roundtrip(wlDisplay) == -1) {
    return EXIT_FAILURE;
  }

  initializeSocket([](std::string request) {
    // std::cout << "Received request: " << request;
    const auto arguments = split(request, " ");
    if (arguments.size() > 0 && arguments[0] == "switch") {
      if (arguments.size() != 6) {
        return "Wrong IPC message length";
      }
      const auto &shaderFile = arguments[1];
      std::cout << "Switching to shader " << shaderFile << "\n";

      if (!compileShaderToySnippetToSpirVFragment(shaderFile,
                                                  spirvUserOutput)) {
        std::cerr << "Could not compile shader for " << shaderFile << "\n";
        return "Could not compile shader";
      }
      sCurrentShaderFile = shaderFile;

      std::lock_guard lock{sMonitorMutex};
      for (auto &monitor : sMonitors) {
        monitor->needsShaderReload = true;
      }
      return "Ok";
    }

    if (arguments.size() > 0 && arguments[0] == "transition") {
      if (arguments.size() != 7) {
        return "Wrong IPC message length";
      }
      const auto &transitionShaderFile = arguments[1];
      const auto &targetShaderFile = arguments[2];
      std::cout << "Transition shader " << transitionShaderFile
                << " from shader " << sCurrentShaderFile << " to shader "
                << targetShaderFile << "\n";

      if (!compileTransitionShaderToSpirVFragment(
              transitionShaderFile, sCurrentShaderFile, targetShaderFile,
              spirvUserOutput)) {
        std::cerr << "Could not compile shader for " << transitionShaderFile
                  << "\n";
        return "Could not compile shader";
      }

      sCurrentShaderFile = targetShaderFile;

      std::lock_guard lock{sMonitorMutex};
      for (auto &monitor : sMonitors) {
        monitor->needsShaderReload = true;
      }

      return "Ok";
    }
    return "Unknown command";
  });

  const auto programStartTime = std::chrono::system_clock::now();
  auto transitionStartTime = std::chrono::system_clock::now();
  int frameNumber = 0;

  do {
    checkAndCreateLayerSurfaces(wlDisplay);

    const auto timeSinceStart =
        std::chrono::system_clock::now() - programStartTime;
    const auto timeSinceStartFloat =
        std::chrono::duration_cast<std::chrono::milliseconds>(timeSinceStart)
            .count() /
        1000.0f;

    const auto renderStart = std::chrono::system_clock::now();

    std::unique_lock lock{sMonitorMutex};
    for (const auto &monitor : sMonitors) {
      if (!monitor->initialized) {
        continue;
      }

      if (monitor->renderer == nullptr) {
        monitor->renderer = std::make_unique<VkPaperRenderer>(
            wlDisplay, (wl_surface *)monitor->wlSurface->resource());

        if (iChannel0) {
          monitor->renderer->loadImageForSampler(0, *iChannel0);
        }
        if (iChannel1) {
          monitor->renderer->loadImageForSampler(1, *iChannel1);
        }
        if (iChannel2) {
          monitor->renderer->loadImageForSampler(2, *iChannel2);
        }
        if (iChannel3) {
          monitor->renderer->loadImageForSampler(3, *iChannel3);
        }
      }

      if (monitor->needsShaderReload) {
        auto fragShaderCode = readBinaryFile(spirvUserOutput);
        if (!fragShaderCode.has_value()) {
          std::cerr << "Could not load user shader!\n";
          monitor->needsShaderReload = false;
          continue;
        }
        monitor->renderer->createGraphicsPipeline(*fragShaderCode);
        monitor->needsShaderReload = false;
        transitionStartTime = std::chrono::system_clock::now();
      }

      const auto timeSinceTransition =
          std::chrono::system_clock::now() - transitionStartTime;
      // todo make transition time configurable
      const auto transitionTimeMs = 3000.0f;
      auto transitionFactor =
          std::chrono::duration_cast<std::chrono::milliseconds>(
              timeSinceTransition)
              .count() /
          transitionTimeMs;
      transitionFactor = std::min(transitionFactor, 1.0f);
      const auto currentUniforms = UniformBuffer{
          timeSinceStartFloat,
          0.0f,
          60.0f,
          frameNumber++,
          transitionFactor,
          0.0f,
          0.0f,
          0.0f,
          Vec4{10, 10, 0, 0},
          Vec3{static_cast<float>(monitor->width),
               static_cast<float>(monitor->height), 0},
      };

      monitor->renderer->updateUniformBuffer(currentUniforms);
      monitor->renderer->drawFrame();
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

    lock.unlock(); // release lock before sleep
    std::this_thread::sleep_for(sleepDuration);
  } while (wl_display_dispatch(wlDisplay) != -1);
}
