cmake_minimum_required(VERSION 3.0.0)
project(Grafos VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(Grafos main.cpp aresta.cpp vertice.cpp buscaLargura.cpp buscaProfundidade.cpp Hierholzer.cpp dijkstra.cpp grafo.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
