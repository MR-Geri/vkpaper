#include "render.hpp"

#include "protocols/wayland.hpp"
#include "protocols/wlr-layer-shell-unstable-v1.hpp"

#include <wayland-client-protocol.h>
#include <wayland-client.h>

#include <chrono>
#include <cstdint>
#include <iostream>
#include <memory>
#include <thread>

struct Monitor {
  std::unique_ptr<CCWlOutput> output;
  std::unique_ptr<CCWlSurface> wl_surface;
  std::unique_ptr<CCZwlrLayerSurfaceV1> layer_surface;
  std::unique_ptr<VkPaperRenderer> renderer;
  int32_t width, height;
  bool initialized;
};
static std::vector<Monitor> s_monitors;

static std::unique_ptr<CCWlCompositor> s_compositor;
static std::unique_ptr<CCZwlrLayerShellV1> s_LayerShell;

static void nop() {}

static void add_interface(void *data, struct wl_registry *registry,
                          uint32_t name, const char *interface,
                          uint32_t version) {
  (void)data;
  if (strcmp(interface, wl_compositor_interface.name) == 0) {
    s_compositor =
        std::make_unique<CCWlCompositor>((wl_proxy *)wl_registry_bind(
            registry, name, &wl_compositor_interface, 4));
  } else if (strcmp(interface, wl_output_interface.name) == 0) {
    auto output = std::make_unique<CCWlOutput>(
        (wl_proxy *)wl_registry_bind(registry, name, &wl_output_interface, 4));
    s_monitors.push_back(
        Monitor{std::move(output), nullptr, nullptr, nullptr, 128, 128, false});
  } else if (strcmp(interface, zwlr_layer_shell_v1_interface.name) == 0) {
    s_LayerShell =
        std::make_unique<CCZwlrLayerShellV1>((wl_proxy *)wl_registry_bind(
            registry, name, &zwlr_layer_shell_v1_interface, 1));
  }
}

static void global_remove(void *data, struct wl_registry *wl_registry,
                          uint32_t name) {}

int main() {
  struct wl_display *wl = wl_display_connect(NULL);
  struct wl_registry *registry = wl_display_get_registry(wl);
  struct wl_registry_listener reg_listener = {.global = add_interface,
                                              .global_remove = global_remove};
  wl_registry_add_listener(registry, &reg_listener, NULL);

  wl_display_dispatch(wl);
  if (wl_display_roundtrip(wl) == -1) {
    return EXIT_FAILURE;
  }

  for (auto &monitor : s_monitors) {
    monitor.wl_surface =
        std::make_unique<CCWlSurface>(s_compositor->sendCreateSurface());
    monitor.layer_surface = std::make_unique<CCZwlrLayerSurfaceV1>(
        s_LayerShell->sendGetLayerSurface(
            monitor.wl_surface->resource(), monitor.output->resource(),
            ZWLR_LAYER_SHELL_V1_LAYER_BACKGROUND, "vkpaper"));

    monitor.layer_surface->sendSetSize(0, 0);
    monitor.layer_surface->sendSetAnchor(
        (zwlrLayerSurfaceV1Anchor)(ZWLR_LAYER_SURFACE_V1_ANCHOR_TOP |
                                   ZWLR_LAYER_SURFACE_V1_ANCHOR_RIGHT |
                                   ZWLR_LAYER_SURFACE_V1_ANCHOR_BOTTOM |
                                   ZWLR_LAYER_SURFACE_V1_ANCHOR_LEFT));
    monitor.layer_surface->sendSetExclusiveZone(-1);

    monitor.layer_surface->setConfigure([&monitor](CCZwlrLayerSurfaceV1 *r,
                                                   uint32_t serial, uint32_t x,
                                                   uint32_t y) {
      std::cout << "configuring monitor with serial " << serial << "..."
                << std::endl;
      r->sendAckConfigure(serial);

      monitor.initialized = true;
    });

    monitor.wl_surface->sendCommit();
  }

  // this is necessary to trigger layer_surface configure before we attach to
  // the surface via vulkan
  if (wl_display_dispatch(wl) == -1) {
    std::cout << "Initial wl_display_dispatch failed!" << std::endl;
  }

  for (auto &monitor : s_monitors) {
    monitor.renderer = std::make_unique<VkPaperRenderer>(
        wl, (wl_surface *)monitor.wl_surface->resource());
  }

  for (;;) {
    const auto renderStart = std::chrono::system_clock::now();
    for (const auto &monitor : s_monitors) {
      monitor.renderer->frame();
    }
    const auto renderEnd = std::chrono::system_clock::now();
    const auto duration = renderEnd - renderStart;
    const auto sleep_duration = std::chrono::milliseconds{16} -
                                duration; // todo: ensure this is positive
    const auto duration_us =
        std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
    const auto sleep_time_us =
        std::chrono::duration_cast<std::chrono::microseconds>(sleep_duration)
            .count();
    std::cout << "rendered vkpaper frame in " << duration_us / 1000.0f
              << "ms, sleeping for " << sleep_time_us / 1000.0f << "ms..."
              << std::endl;

    std::this_thread::sleep_for(sleep_duration);
  }

  while (wl_display_dispatch(wl) != -1) {
  }
}
