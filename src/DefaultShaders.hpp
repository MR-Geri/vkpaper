#pragma once

#include <string>

const auto defaultVertexShader = std::string{R"glsl(
#version 450

layout(location = 0) in vec2 in_position;

layout(location = 0) out vec2 out_uv;

void main() {
    gl_Position = vec4(in_position, 0.0, 1.0);
    out_uv = in_position * 0.5 + 0.5;
}
)glsl"};

const auto fragmentPre = std::string{R"glsl(
#version 450

layout(location = 0) in vec2 in_uv;

layout(location = 0) out vec4 out_color;

layout(std140, binding = 0) uniform UniformBufferObject {
    float iTime;
    float iTimeDelta;
    float iFrameRate;
    int iFrame;

    vec4 iMouse;
    vec3 iResolution;

    vec3 iChannelResolution[4];
    float iChannelTime[4];
};

layout(binding = 1) uniform sampler2D iChannel0;
layout(binding = 2) uniform sampler2D iChannel1;
layout(binding = 3) uniform sampler2D iChannel2;
layout(binding = 4) uniform sampler2D iChannel3;
)glsl"};

const auto fragmentPost = std::string{R"glsl(
void main() {
    vec2 opengl_fragcoord = vec2(gl_FragCoord.x, iResolution.y - gl_FragCoord.y);
    mainImage(out_color, opengl_fragcoord);
    out_color.rgb = pow(out_color.rgb, vec3(2.2)); // linear to sRGB
}
)glsl"};

const auto defaultFragmentShader = fragmentPre + std::string{R"glsl(
void mainImage(out vec4 frag_color, in vec2 frag_coord) {
   frag_color = vec4(in_uv.x, in_uv.y, sin(iTime) * 0.5 + 0.5, 1.0); 
}
)glsl"} + fragmentPost;
