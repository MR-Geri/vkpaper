cmake_minimum_required(VERSION 3.15)

project(
    vkpaper
    VERSION 0.1
    LANGUAGES CXX)

find_package(Vulkan REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(
    deps
    REQUIRED
    IMPORTED_TARGET
    wayland-client
    wayland-protocols
)

add_executable(vkpaper main.cpp render.cpp
    protocols/wayland.cpp
    protocols/wlr-layer-shell-unstable-v1.cpp
    protocols/xdg-shell.cpp
)
target_link_libraries(vkpaper PkgConfig::deps vulkan)

add_custom_target(shaders ALL
    COMMAND glslc shaders/default.frag -o shaders/default.frag.spv
    COMMAND glslc shaders/default.vert -o shaders/default.vert.spv
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
