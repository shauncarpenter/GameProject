#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "shader_management.h"

void print_shader_info_log(GLuint object);
void print_program_info_log(GLuint object);

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

  print_shader_info_log(shader);

  free(shader_text);
  return shader;
}

//The shader program identifier.
GLuint program;

//Shader attributes.
GLuint vertex_attribute, colour_attribute;

//Uniform attributes.
GLuint projection_attribute, view_attribute, model_attribute;

//Makes a program with the given shaders
GLuint make_program(char* vert_file, char* frag_file){

  GLuint vert, frag;
  vert = make_shader(GL_VERTEX_SHADER, vert_file);
  frag = make_shader(GL_FRAGMENT_SHADER, frag_file);

  program = glCreateProgram();

  glAttachShader(program, vert);
  glAttachShader(program, frag);
  
  glBindFragDataLocation(program, 0, "frag_out");
  glLinkProgram(program);

  print_program_info_log(program);

  //Extract attribute locations
  vertex_attribute = glGetAttribLocation(program, "position");

  //Extract uniform locations
  projection_attribute = glGetUniformLocation(program, "projection");
  view_attribute = glGetUniformLocation(program, "view");
  //  model_attribute = glGetUniformLocation(program, "model");

  printf("%d   %d\n", projection_attribute, view_attribute);

  return program;
}

void activate_program(){
  glUseProgram(program);
}

void print_shader_info_log(GLuint object)
{
    int infologLength = 0;
    int charsWritten  = 0;
    char *infoLog;
 
    glGetShaderiv(object, GL_INFO_LOG_LENGTH,&infologLength);
 
    if (infologLength > 0)
    {
        infoLog = (char *)malloc(infologLength);
        glGetShaderInfoLog(object, infologLength, &charsWritten, infoLog);
        printf("%s\n",infoLog);
        free(infoLog);
    }
}

void print_program_info_log(GLuint object){
    int infologLength = 0;
    int charsWritten  = 0;
    char *infoLog;
 
    glGetProgramiv(object, GL_INFO_LOG_LENGTH,&infologLength);
 
    if (infologLength > 0)
    {
        infoLog = (char *)malloc(infologLength);
        glGetProgramInfoLog(object, infologLength, &charsWritten, infoLog);
        printf("%s\n",infoLog);
        free(infoLog);
    }
  }
