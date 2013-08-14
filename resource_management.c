#include <stdlib.h>
#include <stdio.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
//#include <assimp/cimport.h>
//#include <assimp/postprocess.h>

#include "resource_management.h"


//Given a file name, imports the models in the scene into the aiScene 
//  Data structure.


aiScene* import_scene(char* file_name){
  aiScene* scene;
  aiPropertyStore* p_store = aiCreatePropertyStore();
  //Tell assimp that all line and point primitives should be removed.
  aiSetImportPropertyInteger(p_store, AI_CONFIG_PP_SBP_REMOVE, 
			     aiPrimitiveType_LINE | 
			     aiPrimitiveType_POINT);

  //Do the import.
  scene = aiImportFile(file_name,
		       aiProcessPreset_TargetRealtime_MaxQuality);

  aiReleasePropertyStore(p_store);
  
  if(!scene){
    printf("Error loading resource file \"%s\".", file_name);
    return NULL;
  }

  //At this point, the importing has been done successfully.
  return scene;
}

//Releases the memory for the scene.
void release_scene(aiScene* scene){
  aiReleaseImport(scene);
}

//Extracts a mesh from a given scene, storing it in a vertex buffer.
Mesh extract_mesh(aiScene* scene, int mesh_num){
  Mesh mesh;
  aiMesh* assimp_mesh = scene->mMeshes[mesh_num];

  //Create and bind the vertex buffer.
  glGenBuffers(1, &mesh.array_buffer);
  glBindBuffer(GL_ARRAY_BUFFER, mesh.array_buffer);

  //Place the vertex data in the buffer.
  glBufferData(GL_ARRAY_BUFFER, sizeof(float)*assimp_mesh->mNumVertices*3,
	       assimp_mesh->mVertices, GL_STATIC_DRAW);
  
  //Create and bind the index buffer.
  glGenBuffers(1, &(mesh.element_buffer));
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh.element_buffer);
  
  //Transfer the indices from assimp format to a flat array.
  unsigned int* indices = (unsigned int*)malloc(sizeof(unsigned int)*
						assimp_mesh->mNumFaces*3);
  for(int i=0; i<assimp_mesh->mNumFaces; i++){
    aiFace* face = &assimp_mesh->mFaces[i];
    memcpy(&indices[i*3], face->mIndices, 3*sizeof(unsigned int));
  }

  //Transfer that data to the buffer
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int)*mesh.num_faces*3,
	       indices, GL_STATIC_DRAW);


  //Later I will add extracting the texture and normal data.
  mesh.num_faces = assimp_mesh->mNumFaces;
  mesh.num_vertices = assimp_mesh->mNumVertices;

  //Clean up
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
  free(indices);
  return mesh;
}
