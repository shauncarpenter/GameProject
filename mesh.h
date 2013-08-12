#include <GL/gl.h>

typedef struct Mesh{
  GLuint array_buffer, element_buffer;
  int num_faces, num_vertices;
}
