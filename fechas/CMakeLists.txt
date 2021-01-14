# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Informática Básica
#
# @author Marlon Eduardo Salazar Amador
# @date 12 Ene 2021
# @brief CMakeLists.txt for the program "fechas"
# CMakeLists.txt defines the whole build
# CMake reads CMakeLists.txt sequentially
#
# Build process:
#   1. cd IB-P12-Classes-GTests-Exercism/fechas/
#   2. mkdir build
#   3. cd build
#   4. cmake ..
#   5. make


cmake_minimum_required(VERSION 3.1)

# set the project name 
project(fechas             
    VERSION 1.0
    DESCRIPTION "A simple CMake project for the exercise 1 'fechas'"
    LANGUAGES CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14) 						# Use c++14
set(CMAKE_CXX_STANDARD_REQUIRED True)

# tell cmake to output binaries here:
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# Debug and release flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# tell cmake where to look for *.h files
include_directories(${PROJECT_SOURCE_DIR}/src)

# Adds an executable target called "fechas" to be built from the source files listed in the command invocation.
add_executable(runTests
    test/test_fechas.cc
    src/fecha.h
    src/fecha.cc
    test/test_fecha.cc
    
add_executable(fechas
    src/fecha.h
    src/fecha.cc
    src/fechas.cc)

