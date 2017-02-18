#include <spdlog/spdlog.h>
#include <glfw/glfw3.h>

#include "Renderer/Renderer.h"

static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void error_callback(int error, const char *description) {
    auto console = spdlog::get("console");
    console->error(std::string(description));
}


int main() {
    auto console = spdlog::stdout_color_mt("console");

    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) {
        console->critical(std::string("Failed to initialize glfw!"));
        exit(EXIT_FAILURE);
    }


    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(640, 480, "AKRenderer", NULL, NULL);

    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
//    glfwSetKeyCallback(window, key_callback);

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    auto renderer = new Renderer();
    renderer->init();
    renderer->printContextInfo();

    auto time = glfwGetTime();

    while (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();
        auto currentTime = glfwGetTime();
        auto deltaTime = currentTime - time;
        renderer->updateAndDraw(deltaTime);
        time = currentTime;
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    exit(EXIT_SUCCESS);
}
