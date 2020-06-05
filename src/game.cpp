#include "game.h"
#include "SDL.h"
#include "constants.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <stdlib.h>

Game::Game() {
  // initial position of ball
  Vec2D initialPos = Vec2D((kScreenWidth - kBallWidth) / 2.0f, 
                           (kScreenHeight - kBallHeight) / 2.0f);
  
  // initialize ball and transfer ownership of initialPos
  ball_ = Ball(std::move(initialPos), kBallWidth, kBallHeight);
}

void Game::Run(Controller const &controller, Renderer &renderer) {
  bool running = true;
  while(running) {
    // run input-update-render game loop
    controller.HandleInput(running);
    Update();
    renderer.Render(ball_);
    
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
  }
}

void Game::Update() {
  return;
}