#include "game.h"
#include "paddle.h"
#include "vec2d.h"
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
  
  // create players
  Paddle p1(Vec2D(50.0f, (kScreenHeight - kPaddleHeight) / 2.0f),
            kPaddleWidth, kPaddleHeight);
  Vec2D scorePos1 = Vec2D(kScreenWidth / 4, 20);
  players_.emplace_back(
    Player("Player1", std::move(p1), std::move(scorePos1)));
  
  Paddle p2(Vec2D(kScreenWidth - 50.0f, 
                 (kScreenHeight - kPaddleHeight) / 2.0f),
            kPaddleWidth, kPaddleHeight);
  Vec2D scorePos2 = Vec2D(3 * kScreenWidth / 4, 20);
  players_.emplace_back(Player("Player2", std::move(p2), std::move(scorePos2)));
}

void Game::Run(Controller const &controller, Renderer &renderer) {
  bool running = true;
  while(running) {
    // run input-update-render game loop
    controller.HandleInput(running);
    Update();
    renderer.Render(ball_, players_);
    
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
  }
}

void Game::Update() {
  return;
}