void mainImage(out vec4 frag_color, in vec2 frag_coord) {
    vec2 uv = frag_coord / iResolution.xy;
    vec2 circle = vec2(cos(iTime), sin(iTime)) * 0.5 + 0.5;

    if (uv.x < circle.x && uv.y < circle.y) {
        frag_color = texture(iChannel0, uv);
    } else if (uv.x > circle.x && uv.y < circle.y) {
        frag_color = texture(iChannel1, uv);
    } else if (uv.x < circle.x && uv.y > circle.y) {
        frag_color = texture(iChannel2, uv);
    } else {
        frag_color = texture(iChannel3, uv);
    }
    
    frag_color.rgb = pow(frag_color.rgb, vec3(1.0 / 2.2));
}
