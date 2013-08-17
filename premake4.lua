solution "Game"
  configurations "Debug"

  project "TheGame.out"
  kind "ConsoleApp"
  language "C"
  files {"**.h", "**.c"}
  buildoptions {"-std=c99"}

  configuration "Debug"
    defines {"DEBUG"}
    flags {"Symbols"}
    buildoptions {"-g"}

  configuration "linux"
    links {"GL","GLU", "glut", "m", "glfw", "GLEW", "assimp"}
    
