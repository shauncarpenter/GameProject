#include <stdlib.h>
#include <stdio.h>

#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/config.h>
#include <assimp/vector3.h>

#include "resource_management.h"


//Given a file name, imports the models in the scene into the aiScene 
//  Data structure.


Scene* import_scene(char* file_name){
  aiScene* assimp_scene;
  Scene* scene = (Scene*)malloc(sizeof(Scene));
  aiPropertyStore* p_store = aiCreatePropertyStore();
  //Tell assimp that all line and point primitives should be removed.
  aiSetImportPropertyInteger(p_store, AI_CONFIG_PP_SBP_REMOVE, 
			     aiPrimitiveType_LINE | 
			     aiPrimitiveType_POINT);

  //Do the import.
  assimp_scene = aiImportFile(file_name,
		       aiProcessPreset_TargetRealtime_MaxQuality);

  aiReleasePropertyStore(p_store);
  
  if(!assimp_scene){
    printf("Error loading resource file \"%s\".", file_name);
    exit(1);
  }

  //At this point, the importing has been done successfully.
  //  Now we extract that into the Mesh data structure.
  scene->meshes = (Mesh*)malloc(sizeof(Mesh)*assimp_scene->mNumMeshes);
  scene->number_meshes = assimp_scene->mNumMeshes;

  for(int i=0; i<assimp_scene->mNumMeshes; i++){
    scene->meshes[i] = extract_mesh(assimp_scene, i);
  }

  return scene;
}

//Releases the memory for the scene.
void release_scene(aiScene* scene){
  aiReleaseImport(scene);
}

//Extracts a mesh from a given scene, storing it in a mesh object.
Mesh extract_mesh(aiScene* scene, int mesh_num){
  aiMesh* assimp_mesh = scene->mMeshes[mesh_num];
  Mesh mesh = make_mesh(assimp_mesh->mNumVertices,
			assimp_mesh->mNumFaces);

  //Copy the assimp vertices
  memcpy(mesh.vertices, assimp_mesh->mVertices, 
	 sizeof(float)*3*assimp_mesh->mNumVertices);
  
  //Copy the assimp Faces into our own face format
  for(int i=0; i<assimp_mesh->mNumFaces; i++){
    aiFace* face = &assimp_mesh->mFaces[i];
    memcpy(&mesh.faces[i], face->mIndices, 3*sizeof(unsigned int));
  }

  return mesh;
}
