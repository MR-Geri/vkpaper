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
} ubo;

void main() {
    out_color = vec4(in_uv.x, in_uv.y, sin(ubo.iTime) * 0.5 + 0.5, 1.0);
}
