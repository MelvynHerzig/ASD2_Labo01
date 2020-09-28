cmake_minimum_required(VERSION 3.15)
project(L1a)

set(CMAKE_CXX_STANDARD 11)

add_executable(L1a main.cpp BFS.h CC.h DFS.h GraphUsingAdjacencyMatrix.cpp GraphUsingAdjacencyMatrix.h)