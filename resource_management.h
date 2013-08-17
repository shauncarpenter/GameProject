#include "scene.h"

typedef struct aiScene aiScene;
typedef struct aiPropertyStore aiPropertyStore;
typedef struct aiMesh aiMesh;
typedef struct aiFace aiFace;

Scene* import_scene(char* file_name);
void release_scene(aiScene* scene);
Mesh extract_mesh(aiScene* scene, int mesh_num);
