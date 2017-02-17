#include <iostream>
#include <glm/common.hpp>
#include <glbinding/gl/gl.h>
#include <glbinding/Binding.h>
#include <glfw/glfw3.h>

using namespace gl;

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main() {
    if (!glfwInit())
    {
        // Initialization failed
    }
    std::cout << "Hello, World!" << std::endl;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
    glfwSetKeyCallback(window, key_callback);
    if (!window)
    {
        // Window or context creation failed
    }
    glfwMakeContextCurrent(window);
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        // Keep running
    }
    glbinding::Binding::initialize();
//    glClear(GL_COLOR_BUFFER_BIT);
    std::cout << glGetString(GL_VENDOR);
//    printf("OpenGL %s, GLSL %s\n", glGetString(GL_VERSION), glGetString(GL_SHADING_LANGUAGE_VERSION));

//    glfwDestroyWindow(window);
//
//    glfwTerminate();
    return 0;
}
