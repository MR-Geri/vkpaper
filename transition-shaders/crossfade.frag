void mainImage(out vec4 frag_color, in vec2 frag_coord) {
    vec4 srcColor;
    mainImageSrc(srcColor, frag_coord);
    vec4 tgtColor;
    mainImageTgt(tgtColor, frag_coord); 

    frag_color = mix(srcColor, tgtColor, iTransition);
}
