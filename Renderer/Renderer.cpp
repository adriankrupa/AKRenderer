//
// Created by Adrian Krupa on 18.02.2017.
//

#include <glbinding/gl/gl.h>
#include <glbinding/Binding.h>
#include <spdlog/spdlog.h>

#include "Renderer.h"
#include "Time.h"


using namespace gl;
using namespace std;


Renderer::Renderer() {}

void Renderer::init() {
    glbinding::Binding::initialize();

}

void Renderer::printContextInfo() {
    auto console = spdlog::get("console");
    console->info("GL_VENDOR: " + string((char *) glGetString(GL_VENDOR)));
    console->info("GL_VERSION: " + string((char *) glGetString(GL_VERSION)));
    console->info("GL_RENDERER: " + string((char *) glGetString(GL_RENDERER)));
    console->info("GL_SHADING_LANGUAGE_VERSION: " + string((char *) glGetString(GL_SHADING_LANGUAGE_VERSION)));
}

void Renderer::updateAndDraw(double deltaTime) {
}
