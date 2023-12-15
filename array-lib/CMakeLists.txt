# Minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.8)

# Name of the project
project(array-lib)

# Add a library to this build. The name of the library is MyLibrary and it
# consists of only the MyLibrary.cpp file
add_library(array-lib array1d.cpp array2d.cpp)
