cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
tarjet_compile_features(fechas PRIVATE cxx_std_20)

project(fechas)

add_executable(fechas
  src/fechas.cc 
  src/fecha.cc
  src/fecha.h
)
