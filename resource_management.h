#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/config.h>

#include "mesh.h"

typedef struct aiScene aiScene;
typedef struct aiPropertyStore aiPropertyStore;
typedef struct aiMesh aiMesh;
typedef struct aiFace aiFace;

aiScene* import_scene(char* file_name);
void release_scene(aiScene* scene);
Mesh extract_mesh(aiScene* scene, int mesh_num);
