solution "avl"
  configurations {"debug", "release"}

  configuration {"debug"}
    defines {"DEBUG"}

  configuration {"release"}
    flags {"OptimizeSpeed"}

  configuration {"linux"}
		buildoptions { "-mtune=native -march=native" }
		buildoptions { "-std=c++11" }
		buildoptions { "-W -Wall -Wextra", "-pipe" }

  configuration{"linux", "debug"}
    buildoptions {"-g"}
    linkoptions {"-g"}

project "avl"
  language "c++"
  kind "ConsoleApp"
  targetdir "bin"
  files {"noeud.hpp", "noeud.cpp", "arbre.hpp", "arbre.cpp", "main.cpp"}
