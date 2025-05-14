#ifndef GAME_H
#define GAME_H

#include "SCENE.h"
#include "SDL.h"

class Game {
public:
  Game();
  ~Game();
  void run();
  void init();
  void update();
  void render();
  void clean();
  void changeScene(Scene* scene);

  void handleEvent(SDL_Event *event);

private:
  bool isRunning = true;
  Scene* currentScene = nullptr;
  SDL_Window* window = nullptr;
  SDL_Renderer* renderer = nullptr;
  int windowWidth = 600;
  int windowHeight = 800;
};

#endif