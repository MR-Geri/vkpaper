void mainImage(out vec4 frag_color, in vec2 frag_coord) {
    vec4 srcColor;
    mainImageSrc(srcColor, frag_coord);
    vec4 tgtColor;
    mainImageTgt(tgtColor, frag_coord); 

    vec2 uv = frag_coord / iResolution.xy;
    if (uv.x > iTransition) {
        frag_color = srcColor;
    }
    else {
        frag_color = tgtColor;
    }
}
