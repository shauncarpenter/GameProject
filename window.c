#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include <GLFW/glfw3.h>

#include "window.h"

GLFWwindow* window;

void error_callback(int error, char* description){
  printf(description);
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
  window = glfwCreateWindow(x, y, title, NULL, NULL);
  glfwMakeContextCurrent(window);
}

void destroy_window(){
  glfwDestroyWindow(window);
  glfwTerminate();
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
  
