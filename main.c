/*
 
  Simple GLSL 1.5 Demo
 
  www.lighthouse3d.com
 
*/
 
#include <stdio.h>

#include "window.h"
#include "shader_management.h"
#include "buffers.h"
#include "resource_management.h"
 
char *vertex_file_name = "shaders/vertex.glsl";
char *fragment_file_name = "shaders/fragment.glsl";
 
int main() {
  init_window(640,480, "Testing");    
  
  Scene* scene = import_scene("models/untitled.obj");

  make_program(vertex_file_name, fragment_file_name);
  
  initialize_buffers(scene);
 
  while(!check_closed()){
    activate_program();
    set_view_matrix();
    draw_everything();
    next_frame();
  }
  return(0); 
}
