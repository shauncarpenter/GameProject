#ifndef MESH_H
#define MESH_H

//A simple 3D single-precision coordinate.
typedef struct Vector3{
  float x, y, z;
} Vector3;

//Description of a polygon.  Always a triangle.
typedef struct Face{
  int indices[3];
} Face;
  
//A polygon mesh.  Composed of a number of vertices, and a number of faces
//  that reference those vertices.
typedef struct Mesh{
  Vector3* vertices;
  Face* faces;
  int number_faces;
  int number_vertices;
} Mesh;

Mesh make_mesh(int num_vertices, int num_faces);

#endif
