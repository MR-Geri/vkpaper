void mainImage(out vec4 frag_color, in vec2 frag_coord) {
   frag_color = foovec4(in_uv.x, in_uv.y, sin(iTime) * 0.5 + 0.5, 1.0); 
}
