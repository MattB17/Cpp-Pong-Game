#include "game.h"
#include "controller.h"
#include "renderer.h"
#include <iostream>

int main() {
  constexpr std::size_t kScreenWidth{1280};
  constexpr std::size_t kScreenHeight{720};
  constexpr int kBallWidth{15};
  constexpr int kBallHeight{15};
  
  Renderer renderer;
  Controller controller;
  Game game;
  game.Run(controller, renderer);
  std::cout << "The game has terminated successfully" << std::endl;
  return 0;
}