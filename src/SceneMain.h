#ifndef SCENEMAIN_H
#define SCENEMAIN_H

#include "Scene.h"

class SceneMain : public Scene{
public:
    SceneMain();
    ~SceneMain();

    void update() override;
    void render() override;
    void handleEvent(SDL_Event *event) override;
    void init();
    void clean();
};

#endif