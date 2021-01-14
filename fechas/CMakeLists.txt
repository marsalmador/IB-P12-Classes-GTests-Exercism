cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
file(GLOB src_fechas RELATIVE "src" "*.cc" ".h")

project(fechas)

add_executable(
  fechas
  fechas.cc 
  fecha.cc
  fecha.h
)
