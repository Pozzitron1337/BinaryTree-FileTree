cmake_minimum_required(VERSION 3.8)
project(Lab5ASD)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp BinaryTree.cpp FileTree.cpp)
add_executable(Lab5ASD ${SOURCE_FILES} BinaryTree.cpp FileTree.cpp)