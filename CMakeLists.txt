cmake_minimum_required(VERSION 3.6)

include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)


project(AKRenderer)

set(CMAKE_CXX_STANDARD 14)

message("GIT_EXECUTABLE='${GIT_EXECUTABLE}'")

set(glm_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/glm")
set(glm_INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/glm")
set(glm_INCLUDE_DIR "${CMAKE_CURRENT_BINARY_DIR}/glm/include")
set(glm_CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${glm_INSTALL_DIR})

message("glm_PREFIX='${glm_PREFIX}'")
message("glm_INSTALL_DIR='${glm_INSTALL_DIR}'")
message("glm_INCLUDE_DIR='${glm_INCLUDE_DIR}'")
message("glm_CMAKE_ARGS='${glm_CMAKE_ARGS}'")

ExternalProject_Add(glm
        PREFIX ${glm_PREFIX}
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        INSTALL_DIR ${glm_INSTALL_DIR}
        CMAKE_ARGS ${glm_CMAKE_ARGS}
        UPDATE_COMMAND ""
        )

set(glfw_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/glfw")
set(glfw_INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/glfw")
set(glfw_INCLUDE_DIR "${CMAKE_CURRENT_BINARY_DIR}/glfw/include")
set(glfw_CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${glfw_INSTALL_DIR})

message("glfw_PREFIX='${glfw_PREFIX}'")
message("glfw_INSTALL_DIR='${glfw_INSTALL_DIR}'")
message("glfw_INCLUDE_DIR='${glfw_INCLUDE_DIR}'")
message("glfw_CMAKE_ARGS='${glfw_CMAKE_ARGS}'")

ExternalProject_Add(glfw
        PREFIX ${glfw_PREFIX}
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        INSTALL_DIR ${glfw_INSTALL_DIR}
        CMAKE_ARGS ${glfw_CMAKE_ARGS}
        UPDATE_COMMAND ""
        )

set(SOURCE_FILES main.cpp)
add_executable(AKRenderer ${SOURCE_FILES})

add_dependencies(AKRenderer glm)
add_dependencies(AKRenderer glfw)

include_directories(${glm_INCLUDE_DIR})
include_directories(${glfw_INCLUDE_DIR})


target_link_libraries(AKRenderer ${glfw_INSTALL_DIR}/lib/libglfw3.a)