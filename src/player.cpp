#include "player.h"

Player::Player(std::string name, 
               Paddle paddle, 
               std::unique_ptr<Vec2D> scoreDisplayPos)
  : name_(name), paddle_(paddle){
  scoreDisplayPos_ = std::move(scoreDisplayPos);
  score_ = std::make_unique<int>(0);
}

void Player::UpdatePaddlePosition(float elapsedTime) {
  paddle_.UpdatePosition(elapsedTime);
}

void Player::UpdatePaddleVelocityY(float y) {
  paddle_.UpdateVelocityY(y);
}