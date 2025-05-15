# vkpaper

A Vulkan based wallpaper engine for wayland compositors which implement `wlr_layer_shell` (tested on hyprland and KDE Plasma).
It can render (most) shaders in [ShaderToy](https://www.shadertoy.com/) format and provides a way to write your own transitions.

**vkpaper is in alpha**: The interface of vkpaper can (and probably will) change at some point. Please open issues if you find bugs or you have use cases which are not covered.

## Demo

In this video I showcase three transition shaders: a noisy transition, a growing ellipse and a simple move-in animation. Shader credit goes to [knarkowicz](https://www.shadertoy.com/view/4s2yW1) and [nimitz](https://www.shadertoy.com/view/Mts3zM).

https://cgphilipp.de/video/screencast-vkpaper.webm

## Shader compatibility

I am trying to make vkpaper shaders as compatible with [ShaderToy](https://shadertoy.com/) as possible.
Therefore, vkpaper supports all uniform inputs with the same names as given by ShaderToy.

**Note**: at the moment the following ShaderToy uniforms exist (to allow shader compilation), but do not have the correct values:
- `iMouse`
- `iTimeDelta`
- `iFrameRate`
- `iChannelResolution`

There are some features that are out of scope at this point:
- intermediate buffers
- videos, cubemaps, volume textures as sampler inputs
- mouse input

## Building

In the root directory of this repository, build vkpaper with
```sh
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make
```

To install `vkpaper` on your system call this in the "build" directory:
```sh
sudo make install
```

## Usage

**1. option: Start vkpaper with a single shader:**
```sh
vkpaper <path to shader>
```

To use a shader with texture inputs use:
```sh
vkpaper <path to shader> -iChannel0 <path to image>
```
Up to 4 texture inputs are supported via the flags `-iChannel0` through `-iChannel3`.
Currently, all image type supported by [stb_image](https://github.com/nothings/stb) are supported. This includes jpg, png, bmp, gif and more.

**2. option: Start vkpaper in daemon mode and use vkpaperctl to switch between shaders:**

Start `vkpaper` without any arguments as part of your window manager or run it as a background process like this:
```sh
vkpaper &
```

While vkpaper is running, you can now issue commands via `vkpaperctl` to switch shaders dynamically. Or write your own shell scripts to issue `vkpaperctl`  commands based on time, key presses etc. Get creative with it :)

*Switch to a shader instantaneously:*
```sh
vkpaperctl switch <path to shader file>
```

*Use a transition shaders (see below) to transition to a new effect:*
```sh
vkpaperctl transition <path to shader file> -t <time in seconds> -s <path to transition shader>
```

## Transition shaders

A transition shader is a special type of shader to program your own transitions for vkpaper.

It must contain a function with the signature `void mainImage(out vec4 frag_color, in vec2 frag_coord)` where `frag_coord` is the pixel position and `frag_color` is the result of the color of the transition effect.
The uniform `iTransition` specifies how far the transition has progressed within a range of 0-1.
A transition shader may call `mainImageSrc` and `mainImageTgt` to get the color values of source and target shaders like this:
```glsl
void mainImage(out vec4 frag_color, in vec2 frag_coord) {
    vec4 srcColor;
    mainImageSrc(srcColor, frag_coord);
    vec4 tgtColor;
    mainImageTgt(tgtColor, frag_coord); 

    frag_color = mix(srcColor, tgtColor, iTransition);
}
```
This implements a cross-fade effect, one of the simplest transition shaders possible.
For more examples, have a look at the "transition-shaders" directory.

## Limitations

Since transitions are currently implemented by "copy-pasting" the source shader, target shader and transition shader together, there can be incompatibilities.
This can happen when source and transition shaders are using global variables with the same name and will lead to shader compilation errors.

In the future I may try to avoid this by using render-to-texture instead to separate shader executions.
But combining the shaders has the advantage of being easier to implement/maintain and also has performance benefits.

## Similar tools

- [swww](https://github.com/LGFae/swww) - this gave me the idea to use socket-based communication for `vkpaperctl`, they also have amazing performance for animated backgrounds using gifs, check it out!
- [hyprpaper](https://github.com/hyprwm/hyprpaper) - a simpler alternative if all you want are static images

## Shoutout to

- [args](https://github.com/Taywee/args) for providing an awesome header-only option parsing library
- [VulkanTutorial](https://github.com/Overv/VulkanTutorial) for providing a starting point for the vulkan implementation
- [hyprpaper](https://github.com/hyprwm/hyprpaper) for showing how to integrate `wlr_layer_shell`

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
