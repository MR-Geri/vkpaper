cmake_minimum_required(VERSION 3.15)

project(
    vkpaper
    VERSION 0.1
    LANGUAGES CXX
)

find_package(Vulkan REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(
    deps
    REQUIRED
    IMPORTED_TARGET
    wayland-client
    shaderc
)

add_executable(vkpaper src/main.cpp
    src/VkPaperRenderer.cpp
    src/VulkanImage.cpp
    src/VulkanUtils.cpp
    src/ShaderCompile.cpp
    src/FileUtils.cpp
    thirdparty/protocols/wayland.cpp
    thirdparty/protocols/wlr-layer-shell-unstable-v1.cpp
    thirdparty/protocols/xdg-shell.cpp
)
target_link_libraries(vkpaper PRIVATE PkgConfig::deps vulkan)
target_include_directories(vkpaper PRIVATE ${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/thirdparty)
set_target_properties(vkpaper PROPERTIES
    CXX_STANDARD 20
    CXX_EXTENSIONS OFF
)

add_executable(vkpaperctl src/vkpaperctl/main.cpp)
set_target_properties(vkpaperctl PROPERTIES
    CXX_STANDARD 20
    CXX_EXTENSIONS OFF
)
target_include_directories(vkpaperctl PRIVATE ${CMAKE_SOURCE_DIR}/thirdparty)
