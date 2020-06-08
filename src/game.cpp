#include "game.h"
#include "paddle.h"
#include "vec2d.h"
#include "constants.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <chrono>
#include <algorithm>

Game::Game() {
  // initial position of ball
  Vec2D initialPos = Vec2D((kScreenWidth - kBallWidth) / 2.0f, 
                           (kScreenHeight - kBallHeight) / 2.0f);
  
  // initialize ball and transfer ownership of initialPos
  ball_ = Ball(std::move(initialPos),
               Vec2D(kBallSpeed, 0.0f), 
               kBallWidth, 
               kBallHeight);
  
  // create players
  Paddle p1(Vec2D(50.0f, (kScreenHeight - kPaddleHeight) / 2.0f),
            Vec2D(0.0f, 0.0f),
            kPaddleWidth, 
            kPaddleHeight);
  Vec2D scorePos1 = Vec2D(kScreenWidth / 4, 20);
  players_.emplace_back(
    Player("Player1", std::move(p1), std::move(scorePos1)));
  
  Paddle p2(Vec2D(kScreenWidth - 50.0f, 
                 (kScreenHeight - kPaddleHeight) / 2.0f),
            Vec2D(0.0f, 0.0f),
            kPaddleWidth, 
            kPaddleHeight);
  Vec2D scorePos2 = Vec2D(3 * kScreenWidth / 4, 20);
  players_.emplace_back(Player("Player2", std::move(p2), std::move(scorePos2)));
}

void Game::Run(Controller const &controller, Renderer &renderer) {
  bool running = true;
  float elapsedTime = 0.0f;
  while(running) {
    auto startTime = std::chrono::high_resolution_clock::now();
    
    // run input-update-render game loop
    controller.HandleInput(running, players_);
    Update(elapsedTime);
    renderer.Render(ball_, players_);
    
    auto stopTime = std::chrono::high_resolution_clock::now();
    elapsedTime = std::chrono::duration<float, std::chrono::milliseconds::period>(stopTime - startTime).count();
  }
}

void Game::Update(float elapsedTime) {
  
  // update position of paddles
  for (auto &player : players_) {
    player.UpdatePaddlePosition(elapsedTime);
  }
  
  // update ball position
  ball_.UpdatePosition(elapsedTime);
  
  // check for collision with a paddle
  Contact contact{};
  for (auto player : players_) {
    contact = BallHitPaddle(player.GetPaddle());
    if (contact.collisionType != CollisionType::kNone) {
      ball_.HandleObjectCollision(contact);
      break;
    }
  }
}

Contact Game::BallHitPaddle(Paddle paddle) {
  Contact contact{};
  
  float ballLeft = ball_.GetPosition().GetX();
  float ballRight = ballLeft + ball_.GetWidth();
  
  float paddleLeft = paddle.GetPosition().GetX();
  float paddleRight = paddleLeft + paddle.GetWidth();
  
  // if they don't overlap on the x axis return false
  if ((ballRight < paddleLeft) || (ballLeft > paddleRight)) {
    return contact;
  }
  
  float ballTop = ball_.GetPosition().GetY();
  float ballBottom = ballTop + ball_.GetHeight();
  
  float paddleTop = paddle.GetPosition().GetY();
  float paddleBottom = paddleTop + paddle.GetHeight();
  
  // if they don't overlap on the y axis return false
  if ((ballBottom < paddleTop) || (ballTop > paddleBottom)) {
    return contact;
  }
  
  // otherwise, they collide on both axes
  
  // set level of penetration
  if (ball_.GetVelocity().GetX() < 0) {
    // hit object from the right
    contact.penetration = paddleRight - ballLeft;
  } else if (ball_.GetVelocity().GetX() > 0) {
    // hit object from the left
    contact.penetration = paddleLeft - ballRight;
  }
  
  // the top is denoted as the top 1/3rd, and the bottom is the bottom 1/3rd
  float paddleRangeUpper = paddleBottom - (2.0f * paddle.GetHeight() / 3.0f);
  float paddleRangeMiddle = paddleBottom - (paddle.GetHeight() / 3.0f);
  
  // determine whether ball hit paddle at top, middle, or bottom
  if ((ballBottom >= paddleTop) && (ballBottom < paddleRangeUpper)) {
    contact.collisionType = CollisionType::kTop;
  } else if ((ballBottom >= paddleRangeUpper) && (ballBottom < paddleRangeMiddle)) {
    contact.collisionType = CollisionType::kMiddle;
  } else {
    contact.collisionType = CollisionType::kBottom;
  }
  
  return contact;
}