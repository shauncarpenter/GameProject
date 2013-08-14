solution "Game"
  configurations "Debug"

  project "TheGame.out"
  kind "ConsoleApp"
  language "C"
  files {"**.h", "**.c"}
  buildoptions {"-std=c99"}

  configuration "linux"
    links {"GL", "glfw", "GLEW", "assimp"}
    
