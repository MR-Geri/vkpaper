# vkpaper

A WIP Vulkan based wallpaper engine for wayland compositors which implement `wlr_layer_shell`.

## TODO

- correctly react to hotswapping, currently wl_display_dispatch blocks if a display is added and rendering from two renderers
- read configuration from `$HOME/.config/vkpaper` (as alternative to setting the shader directly via command line)
- let the user specify an alternative configuration via command line

future features:
- auto reload via filesystem watchers
- support reading input textures similarly to ShaderToy (very useful for noise texture inputs)
- allow setting an FPS limit
- allow textures as an input in addition to shaders (making vkpaper also useful as a regular wallpaper daemon)
  - note: in texture mode we can stop rendering to limit GPU usage
- support animations between multiple configurations (for both shaders and texture modes)

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

## Shoutout to

- https://github.com/Taywee/args for providing an awesome header-only option parsing library
- https://github.com/Overv/VulkanTutorial for providing a starting point for the vulkan implementation
- https://github.com/hyprwm/hyprpaper for showing how to integrate `wlr_layer_shell`
