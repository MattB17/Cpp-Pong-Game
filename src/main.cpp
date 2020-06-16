#include "game.h"
#include "controller.h"
#include "renderer.h"
#include <iostream>

int main() {
  Renderer renderer;
  Controller controller;
  Game game;
  game.Run(controller, renderer);
  std::cout << "The game has terminated successfully" << std::endl;
  return 0;
}