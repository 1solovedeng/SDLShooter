#include "Game.h"
#include "SceneMain.h"
#include "SDL.h"



Game::Game() {
}

Game::~Game() {
  clean();
}

void Game::run() {
  while(isRunning)  {
    SDL_Event event;
    handleEvent(&event);

    update();

    render();
  } 
}

void Game::init() {
  // SDL初始化
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL_Init Error:%S\n", SDL_GetError());
    isRunning = false;


  }
  // 创建窗口
  window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);

  if (window == nullptr) {
    SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL_CreateWindow Error:%S\n", SDL_GetError());
    isRunning = false;
  }

  // 创建渲染器
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (renderer == nullptr) {
    SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL_CreateRenderer Error:%S\n", SDL_GetError());
    isRunning = false;
  }

  currentScene = new SceneMain();
  }

void Game::handleEvent(SDL_Event *event) {
      while (SDL_PollEvent(event)) {
      if (event->type == SDL_QUIT) {
        isRunning = false;
      }
      currentScene->handleEvent(event);
    }
}

void Game::update() {
  currentScene->update();
}

void Game::render() {
      // 清空
    SDL_RenderClear(renderer);

    currentScene->render();
    // 显示更新
    SDL_RenderPresent(renderer);
}

void Game::clean() {

  if (currentScene != nullptr) {
    currentScene->clean();
    delete currentScene;
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void Game::changeScene(Scene *scene) {
  if (currentScene != nullptr) {
    currentScene->clean();
    delete currentScene;
  }
  currentScene = scene;
  currentScene->init();
}
