#include <stdlib.h>
#include <stdio.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "window.h"

GLFWwindow* window;

void error_callback(int error, const char* description){
  printf(description);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
  if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
    glfwSetWindowShouldClose(window, GL_TRUE);
  }
}

//creates a window with the given dimensions and title.
void init_window(int x, int y, char* title){
  static bool already_init = false;
  
  if(!already_init){
    glfwSetErrorCallback(error_callback);
    
    if(!glfwInit()){
      exit(EXIT_FAILURE);
    }

    already_init = true;
  }

  if(!window){
    glfwDestroyWindow(window);
  }
  
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  window = glfwCreateWindow(x, y, title, NULL, NULL);
  glfwMakeContextCurrent(window);
  glewExperimental = GL_TRUE;
  glewInit();

  glEnable(GL_DEPTH_TEST);
  glClearColor(0.0,0.0,0.0,0.0);

  glfwSetKeyCallback(window, key_callback);
}

void destroy_window(){
  glfwDestroyWindow(window);
  glfwTerminate();
}

bool check_closed(){
  return glfwWindowShouldClose(window);
}
//Handles transitioning to the next frame.  Swaps buffers, polls events, 
//  sets timers.  Returns the time since the last call of this function.

double next_frame(){
  static double time = 0;
  double next_time;

  glfwSwapBuffers(window);
  glfwPollEvents();

  next_time = glfwGetTime() - time;
  time = next_time;
  return time;
}
  
