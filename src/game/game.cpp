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
  // initial ball
  std::unique_ptr<Vec2D> ballPos = std::make_unique<Vec2D>((kScreenWidth - kBallWidth) / 2.0f, 
                                                           (kScreenHeight - kBallHeight) / 2.0f);
  std::unique_ptr<Vec2D> ballVelocity = std::make_unique<Vec2D>(kBallSpeed, 0.0f);
  ball_ = std::make_unique<Ball>(std::move(ballPos),
                                 std::move(ballVelocity), 
                                 kBallSpeed,
                                 kBallWidth, 
                                 kBallHeight);
  
  // create players
  float centerY = (kScreenHeight - kPaddleHeight) / 2.0f;
  user_ = std::make_unique<Player>("User", 50.0f, centerY, kScreenWidth / 4.0f);
  computerAI_ = std::make_unique<Player>("ComputerAI", kScreenWidth - 50.0f, centerY, 3 * kScreenWidth / 4.0f);
}

void Game::Run(Controller const &controller, Renderer &renderer) {
  bool running = true;
  int count = 3;
  while (running && count > 0) {
    controller.CheckForQuit(running);
    renderer.RenderCountPage(count, *user_, *computerAI_);
    
    --count;
    
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }
  
  float elapsedTime = 0.0f;
  while(running) {
    auto startTime = std::chrono::high_resolution_clock::now();
    
    // run input-update-render game loop
    controller.HandleInput(running, *user_, *computerAI_);
    Update(elapsedTime, renderer);
    renderer.Render(*ball_, *user_, *computerAI_);
    
    auto stopTime = std::chrono::high_resolution_clock::now();
    elapsedTime = std::chrono::duration<float, std::chrono::milliseconds::period>(stopTime - startTime).count();
  }
}

void Game::Update(float elapsedTime, Renderer const &renderer) {
  
  // update position of paddles
  user_->UpdatePaddlePosition(elapsedTime);
  computerAI_->UpdatePaddlePosition(elapsedTime);
  
  // update ball position
  ball_->UpdatePosition(elapsedTime);
  
  // check for collision with a paddle
  Contact contact = GetBallPaddleContact(user_->GetPaddle());
  if (contact.IsHit()) {
    // if hit user's paddle, update accordingly
    HandleBallPaddleContact(contact, renderer);
  } else {
    contact = GetBallPaddleContact(computerAI_->GetPaddle());
    if (contact.IsHit()) {
      // if hit computerAI's paddle, update accordingly
      HandleBallPaddleContact(contact, renderer);
    } else {
      // otherwise, check if it hit wall
      contact = GetBallWallContact();
      if (contact.collisionType != CollisionType::kNone) {
        ball_->HandleWallCollision(contact);
      
        // increment appropriate player's score depending on collision type
        if (contact.collisionType == CollisionType::kLeft) {
          user_->IncrementScore();
        } else if (contact.collisionType == CollisionType::kRight) {
          computerAI_->IncrementScore();
        } else {
          renderer.PlayWallHitSound();
        }
      }
    }
  }
}

void Game::HandleBallPaddleContact(Contact contact, Renderer const &renderer) {
  ball_->HandleObjectCollision(contact);
  renderer.PlayObjectHitSound();
}

Contact Game::GetBallPaddleContact(Paddle const &paddle) {
  // contact is initialized with CollisionType of kNone
  Contact contact{};
  
  float ballLeft = ball_->GetPosition().GetX();
  float ballRight = ballLeft + ball_->GetWidth();
  
  float paddleLeft = paddle.GetPosition().GetX();
  float paddleRight = paddleLeft + paddle.GetWidth();
  
  // if they don't overlap on the x axis return false
  if ((ballRight < paddleLeft) || (ballLeft > paddleRight)) {
    return contact;
  }
  
  float ballTop = ball_->GetPosition().GetY();
  float ballBottom = ballTop + ball_->GetHeight();
  
  float paddleTop = paddle.GetPosition().GetY();
  float paddleBottom = paddleTop + paddle.GetHeight();
  
  // if they don't overlap on the y axis return false
  if ((ballBottom < paddleTop) || (ballTop > paddleBottom)) {
    return contact;
  }
  
  // otherwise, they collide on both axes
  
  // set level of penetration
  if (ball_->GetVelocity().GetX() < 0) {
    // hit object from the right
    contact.penetration = paddleRight - ballLeft;
  } else if (ball_->GetVelocity().GetX() > 0) {
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

Contact Game::GetBallWallContact() {
  // contact is initialized with CollisionType of kNone
  Contact contact{};
  
  float ballLeft = ball_->GetPosition().GetX();
  float ballRight = ballLeft + ball_->GetWidth();
  float ballTop = ball_->GetPosition().GetY();
  float ballBottom = ballTop + ball_->GetHeight();
  
  if (ballLeft <= 0.0f) {
    // hit left wall
    contact.collisionType = CollisionType::kLeft;
  } else if (ballRight >= kScreenWidth) {
    // hit right wall
    contact.collisionType = CollisionType::kRight;
  } else if (ballTop <= 0.0f) {
    // hit top wall
    contact.collisionType = CollisionType::kTop;
    contact.penetration = -ballTop;
  } else if (ballBottom >= kScreenHeight) {
    // hit bottom wall
    contact.collisionType = CollisionType::kBottom;
    contact.penetration = ballBottom - kScreenHeight;
  }
  
  return contact;
}