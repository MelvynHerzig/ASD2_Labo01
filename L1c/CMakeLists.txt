cmake_minimum_required(VERSION 3.16)
project(L1c)

set(CMAKE_CXX_STANDARD 11)

add_executable(L1c main.cpp GraphUsingAdjacencyLists.cpp GraphUsingAdjacencyLists.h SymbolGraph.h Util.cpp Util.h)