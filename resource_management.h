#include <assimp/scene.h>

#include "mesh.h"

aiScene* import_scene(char* file_name);
void release_scene(aiScene* scene);
Mesh extract_mesh(aiScene* scene, int mesh_num);
