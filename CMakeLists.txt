cmake_minimum_required(VERSION 3.6)

include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)


project(AKRenderer)

set(CMAKE_CXX_STANDARD 14)

message("GIT_EXECUTABLE='${GIT_EXECUTABLE}'")


set(SOURCE_FILES main.cpp)
add_executable(AKRenderer ${SOURCE_FILES})

add_subdirectory(Libraries)


add_dependencies(AKRenderer glm)
add_dependencies(AKRenderer glfw)
add_dependencies(AKRenderer glbinding)
add_dependencies(AKRenderer spdlog)


include_directories(${glfw_INCLUDE_DIR})
include_directories(${glbinding_INCLUDE_DIR})
include_directories(${spdlog_INCLUDE_DIR})
include_directories(${glm_INCLUDE_DIR})

add_subdirectory(Renderer)


target_link_libraries(AKRenderer Renderer)

target_link_libraries(AKRenderer ${glfw_INSTALL_DIR}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}glfw3${CMAKE_STATIC_LIBRARY_SUFFIX})
target_link_libraries(AKRenderer ${glbinding_INSTALL_DIR}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}glbinding${CMAKE_STATIC_LIBRARY_SUFFIX})

if (UNIX AND NOT APPLE)
    target_link_libraries(AKRenderer dl X11 pthread GL m GLU Xrandr Xi Xxf86vm Xcursor Xinerama)
endif (UNIX AND NOT APPLE)

if (APPLE)
    FIND_LIBRARY(COCOA_LIBRARY Cocoa)
    FIND_LIBRARY(OPENGL_LIBRARY OpenGL)
    FIND_LIBRARY(IOKit_LIBRARY IOKit)
    FIND_LIBRARY(CORE_VIDEO_LIBRARY CoreVideo)

    message("COCOA_LIBRARY=${COCOA_LIBRARY}")
    message("OPENGL_LIBRARY=${OPENGL_LIBRARY}")
    message("IOKit_LIBRARY=${IOKit_LIBRARY}")
    message("CORE_VIDEO_LIBRARY=${CORE_VIDEO_LIBRARY}")

    target_link_libraries(AKRenderer ${COCOA_LIBRARY})
    target_link_libraries(AKRenderer ${OPENGL_LIBRARY})
    target_link_libraries(AKRenderer ${IOKit_LIBRARY})
    target_link_libraries(AKRenderer ${CORE_VIDEO_LIBRARY})
endif (APPLE)

if (WIN32)
    target_link_libraries(AKRenderer opengl32)
endif (WIN32)