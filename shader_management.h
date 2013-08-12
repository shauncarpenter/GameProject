#include <GLFW/glfw3.h>

char* read_file(char* file_name);
GLuint make_shader(GLenum type, char* file_name);
GLuint make_program(char* vert_file, char* frag_file);

