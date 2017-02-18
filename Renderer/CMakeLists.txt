cmake_minimum_required(VERSION 3.6)

include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)

set(SOURCE_FILES Renderer.cpp Renderer.h)
add_library(Renderer ${SOURCE_FILES})

