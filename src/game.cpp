#include "game.h"
#include "SDL.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <stdlib.h>

Game::Game(int ballWidth, int ballHeight,
           std::size_t screenWidth, std::size_t screenHeight) {
  // initial position of ball
  Vec2D initialPos = Vec2D((screenWidth - ballWidth) / 2.0f, 
                           (screenHeight - ballHeight) / 2.0f);
  
  // initialize ball and transfer ownership of initialPos
  ball_ = Ball(std::move(initialPos), ballWidth, ballHeight);
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