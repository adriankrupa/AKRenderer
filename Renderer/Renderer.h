//
// Created by Adrian Krupa on 18.02.2017.
//

#ifndef AKRENDERER_RENDERER_H
#define AKRENDERER_RENDERER_H


class Renderer {
public:
    Renderer();

    void init();

    void printContextInfo();

    void updateAndDraw(double deltaTime);
};


#endif //AKRENDERER_RENDERER_H
