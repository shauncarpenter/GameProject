uniform mat4 model, view, projection;

in vec3 position;
in vec3 colour;

out vec3 out_colour;

void main(){
  out_colour = colour;
  gl_Position = projection * view * model * position;
}
