#include "player.h"

Player::Player(std::string name, 
               std::unique_ptr<Paddle> paddle, 
               std::unique_ptr<const Vec2D> scoreDisplayPos)
  : name_(name), score_(0) {
  paddle_ = std::move(paddle);
  scoreDisplayPos_ = std::move(scoreDisplayPos);
}

void Player::UpdatePaddlePosition(float elapsedTime) {
  paddle_->UpdatePosition(elapsedTime);
}

void Player::UpdatePaddleVelocityY(float y) {
  paddle_->UpdateVelocityY(y);
}