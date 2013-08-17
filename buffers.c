#include <stdlib.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>


#include "buffers.h"
#include "attributes.h"

#include <stdio.h>

GLuint* vao_array;
int* face_numbers;
int array_size;

GLuint* initialize_buffers(Scene* scene){
  GLuint buffer;
int num_meshes = scene->number_meshes;
  
  face_numbers = (int*)malloc(sizeof(int)*num_meshes);
  printf("%d meshes.\n", num_meshes);
  vao_array = (GLuint*)malloc(sizeof(GLuint)*num_meshes);
  glGenVertexArrays(num_meshes, vao_array);
  array_size = num_meshes;
  
  for(int i=0; i<num_meshes; i++){
    Mesh* mesh = &scene->meshes[i];
    glBindVertexArray(vao_array[i]);
    face_numbers[i] = mesh->number_faces;
    
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int)*3*mesh->number_faces,
		 mesh->faces, GL_STATIC_DRAW);
    
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)*3*mesh->number_vertices,
		 mesh->vertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(vertex_attribute);
    glVertexAttribPointer(vertex_attribute, 3, GL_FLOAT, 0, 0, 0);
  }

  glBindVertexArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

  return vao_array;
}

void draw_everything(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  for(int i=0; i<array_size; i++){
    glBindVertexArray(vao_array[i]);
    glDrawElements(GL_TRIANGLES, face_numbers[i]*3,GL_UNSIGNED_INT, 0);
  }
}

void set_view_matrix(){
  float viewMat[] = {1.0, 0.0, 0.0, 0.0,
		   0.0, 1.0, 0.0, 0.0,
		   0.0, 0.0, 1.0, 0.0,
		   0.0, 0.0, 0.0, 1.0};

  float projMat[] = {2.0, 0.0, 0.0, 0.0,
			0.0, 2.0, 0.0, 0.0,
			0.0, 0.0, -1.0, -1.0,
			0.0, 0.0, -2.0, 0.0};
  glUniformMatrix4fv(view_attribute, 1, GL_FALSE, viewMat);
  glUniformMatrix4fv(projection_attribute, 1, GL_FALSE, projMat);
  glUniformMatrix4fv(model_attribute, 1, GL_FALSE, viewMat);
}
