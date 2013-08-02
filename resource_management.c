#include <assimp/cimport.h>
#include <assimp/postprocess.h>

#include "resource_management.h"

//Given a file name, imports the models in the scene into the aiScene 
//  Data structure.

m

aiScene* import_scene(char* file_name){
  aiScene* scene;
  aiPropertyStore* p_store = aiCreatePropertyStore();
  //Tell assimp that all line and point primitives should be removed.
  aiSetImportPropertyInteger(pStore, AI_CONFIG_PP_SBP_REMOVE, 
			     aiPrimitiveType_LINE | 
			     aiPrimitiveType_POINT);

  //Do the import.
  scene = aiImportFile(file_name,
		       riProcessPreset_TargetRealtime_MaxQuality);

  aiReleasePropertyStore(p_store);
  
  if(!scene){
    printf("Error loading resource file \"\s\".", file_name);
    return NULL;
  }

  //At this point, the importing has been done successfully.
  return scene;
}

//Releases the memory for the scene.
void release_scene(aiScene* scene){
  aiReleaseImport(scene);
}
