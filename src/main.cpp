#include "game.h"
#include "controller.h"
#include "renderer.h"
#include "SDL_runner.h"
#include <iostream>
#include <memory>

int main() {
  std::shared_ptr<SDL_Runner> runner = std::make_shared<SDL_Runner>();
  Renderer renderer(runner);
  Controller controller(std::move(runner));
  Game game;
  game.Run(controller, renderer);
  std::cout << "The game has terminated successfully" << std::endl;
  return 0;
}