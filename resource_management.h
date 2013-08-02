#include <assimp/scene.h>

aiScene* import_scene(char* file_name);
void release_scene(aiScene* scene);
