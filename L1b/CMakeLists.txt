cmake_minimum_required(VERSION 3.16)
project(L1b)

set(CMAKE_CXX_STANDARD 11)

add_executable(L1b main.cpp GraphFromImage.cpp GraphFromImage.h DFS.h)