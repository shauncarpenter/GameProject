in vec3 frag_colour;
out vec4 frag_out;

void main(){
  frag_out = vec3(frag_colour, 1.0);
}
