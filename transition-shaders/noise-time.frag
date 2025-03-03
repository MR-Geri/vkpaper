float randFade(vec2 co){ return fract(sin(dot(co.xy ,vec2(12.9898,78.233))) * 43758.5453); }

void mainImage(out vec4 frag_color, in vec2 frag_coord) {
    vec4 srcColor;
    mainImageSrc(srcColor, frag_coord);
    vec4 tgtColor;
    mainImageTgt(tgtColor, frag_coord); 

    const float gridSize = 20.0;
    vec2 fractCoord = frag_coord / gridSize;
    fractCoord -= fract(fractCoord);

    float randOffset = randFade(fractCoord * iTransition) - 0.5; // for also funky change over time
    float wideTransition = iTransition * 2.0 - 0.5; // [-0.5;1.5]
    float randTransition = clamp(wideTransition + randOffset, 0.0, 1.0);

    frag_color = mix(srcColor, tgtColor, randTransition);
}
