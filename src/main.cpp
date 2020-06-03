#include "game.h"
#include "controller.h"
#include "renderer.h"
#include <iostream>

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

int main() {
  constexpr std::size_t kScreenWidth{1280};
  constexpr std::size_t kScreenHeight{720};
  
  Renderer renderer(kScreenWidth, kScreenHeight);
  Controller controller;
  Game game;
  game.Run(controller, renderer);
  std::cout << "The game has terminated successfully" << std::endl;
  return 0;
}