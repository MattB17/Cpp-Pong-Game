#include "player.h"

Player::Player(std::string name, Paddle paddle, Vec2D scoreDisplayPos)
  : name_(name), 
    paddle_(paddle), 
    scoreDisplayPos_(scoreDisplayPos), 
    score_(0) {}

void Player::UpdatePaddlePosition(float elapsedTime) {
  paddle_.UpdatePosition(elapsedTime);
}

void Player::UpdatePaddleVelocityY(float y) {
  paddle_.UpdateVelocityY(y);
}