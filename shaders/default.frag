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

void mainImage(out vec4 frag_color, in vec2 frag_coord) {
   frag_color = vec4(in_uv.x, in_uv.y, sin(iTime) * 0.5 + 0.5, 1.0); 
}

void main() {
    vec2 opengl_fragcoord = vec2(gl_FragCoord.x, iResolution.y - gl_FragCoord.y);
    mainImage(out_color, opengl_fragcoord);
    out_color.rgb = pow(out_color.rgb, vec3(2.2)); // linear to sRGB
}
