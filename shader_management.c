#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "shader_management.h"

//Reads a file into a string, returns the contents.
char* read_file(char* file_name){
  char* result;
  FILE* file = fopen(file_name, "r");
  int count;
  if(file == NULL){
    printf("Error: File '%s' unsuccessfully opened.\n", file_name);
    return NULL;
  }

  fseek(file, 0, SEEK_END);  
  count = ftell(file);
  rewind(file);

  if(count == 0){
    printf("Error: file '%s' empty.\n", file_name);
    return NULL;
  }

  result = (char*) malloc(sizeof(char)*(count+1));
  count = fread(result, sizeof(char), count, file);
  result[count] = '\0';
  fclose(file);

  return result;
}

//Makes the shader of the given type in the given file, returns its GL
//  identifier.
GLuint make_shader(GLenum type, char* file_name){
  char* shader_text = read_file(file_name);
  
  GLuint shader = glCreateShader(type);
  glShaderSource(shader, 1, (const GLchar **)&shader_text, NULL);

  glCompileShader(shader);
  //TODO: Error check here.
  free(shader_text);
  return shader;
}

//Makes a program with the given shaders
GLuint make_program(char* vert_file, char* frag_file){
  GLuint program = glCreateProgram();
  GLuint vert, frag;
  vert = make_shader(GL_VERTEX_SHADER, vert_file);
  frag = make_shader(GL_FRAGMENT_SHADER, frag_file);

  glAttachShader(program, vert);
  glAttachShader(program, frag);
  
  glBindFragDataLocation(program, 0, "frag_out");
  glLinkProgram(program);
  //TODO: Error check here.

  //TODO: Extract attributes here? globals?
  return program;
}

