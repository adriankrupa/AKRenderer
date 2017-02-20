cmake_minimum_required(VERSION 3.6)

add_subdirectory(Components)

set(SOURCE_FILES Renderer.cpp Renderer.h)
add_library(Renderer ${SOURCE_FILES})
target_link_libraries(Renderer Components)


