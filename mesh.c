#include <stdlib.h>

#include "mesh.h"

Mesh make_mesh(int num_vertices, int num_faces){
  Mesh mesh;

  mesh.vertices = (Vector3*)malloc(sizeof(Vector3)*num_vertices);
  mesh.faces = (Face*)malloc(sizeof(Face)*num_faces);
  mesh.number_faces = num_faces;
  mesh.number_vertices = num_vertices;

  return mesh;
}
