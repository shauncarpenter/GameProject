#version 130

uniform mat4 view, projection;

in vec3 position;
//in vec3 colour;

//out vec3 frag_colour;

void main(){
  //frag_colour = colour;
  gl_Position = projection * view * vec4(position, 1.0);
}
