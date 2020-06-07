#include "paddle.h"
#include "constants.h"
#include <iostream>

Paddle::Paddle(Vec2D position, Vec2D velocity)
  : pos_(position), velocity_(velocity), width_(1), height_(1) {}

Paddle::Paddle(Vec2D position, Vec2D velocity, int width, int height) 
  : pos_(position), velocity_(velocity) {
  SetWidth(width);
  SetHeight(height);
}

void Paddle::UpdatePosition(float elapsedTime) {
  pos_ += velocity_ * elapsedTime;
  if (pos_.GetY() < 0) {
    pos_.SetY(0);
  } else if (pos_.GetY() > (kScreenHeight - height_)) {
    pos_.SetY(kScreenHeight - height_);
  }
}

void Paddle::UpdateVelocityY(float y) {
  velocity_.SetY(y);
}

void Paddle::SetWidth(int width) {
  try {
    if (width <= 0) throw width;
    width_ = width;
  } catch (int e) {
    std::cerr << "Paddle width must be a positive integer. Value " << e << " given" << std::endl;
  }
}

void Paddle::SetHeight(int height) {
  try {
    if (height <= 0) throw height;
    height_ = height;
  } catch (int e) {
    std::cerr << "Paddle height must be a positive integer. Value " << e << " given" << std::endl;
  }
}