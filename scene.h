#ifndef SCENE_H
#define SCENE_H

#include "mesh.h"

typedef struct Scene{
  Mesh* meshes;
  int number_meshes;
} Scene;

#endif
