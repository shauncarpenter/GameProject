#include <GL/glew.h>
#include <GLFW/glfw3.h>

char* read_file(char* file_name);
void activate_program();
GLuint make_program(char* vert_file, char* frag_file);
