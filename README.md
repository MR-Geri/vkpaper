# vkpaper

A WIP Vulkan based wallpaper engine for wayland compositors which implement `wlr_layer_shell`.

## TODO

- correctly react to hotswapping, currently wl_display_dispatch blocks if a display is added and rendering from two renderers
- correctly handle iChannel0-3 during transitions
  - need to rename iChannel0 -> iChannel0Src for source shader and so on
  - then handle mapping via descriptor sets
- after animation finishes, switch to target shader only

future features:
- auto reload via filesystem watchers
- allow setting an FPS limit
- add "static mode" for shaders, so we can stop rendering to limit GPU usage
  - mostly useful for simple wallpaper mode

## Collection of amazing Shadertoy wallpapers

- https://www.shadertoy.com/view/lsl3RH
- https://www.shadertoy.com/view/4s23zz
- https://www.shadertoy.com/view/MdSXzz

- https://www.shadertoy.com/view/4dsGzH
- https://www.shadertoy.com/view/XsBfRW
- https://www.shadertoy.com/view/lscBRf
- https://www.shadertoy.com/view/MsGczV
- https://www.shadertoy.com/view/4s2yW1
- https://www.shadertoy.com/view/llS3RK
- https://www.shadertoy.com/view/MdfBzl
- https://www.shadertoy.com/view/MlsGDs
- https://www.shadertoy.com/view/mdBSRt
- https://www.shadertoy.com/view/4t23RR
- https://www.shadertoy.com/view/7ldcRH
- https://www.shadertoy.com/view/XlsXDB

## Similar tools

- swww
- hyprpaper

## Shoutout to

- https://github.com/Taywee/args for providing an awesome header-only option parsing library
- https://github.com/Overv/VulkanTutorial for providing a starting point for the vulkan implementation
- https://github.com/hyprwm/hyprpaper for showing how to integrate `wlr_layer_shell`
