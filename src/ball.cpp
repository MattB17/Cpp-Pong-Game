#include "ball.h"
#include <iostream>

void Ball::SetWidth(int width) {
  try {
    if (width <= 0) throw width;
    width_ = width;
  } catch (int e) {
    std::cerr << "Ball width must be a positive integer. Value " << e << " given." << std::endl;
  }
}

void Ball::SetHeight(int height) {
  try {
    if (height <= 0) throw height;
    height_ = height;
  } catch (int e) {
    std::cerr << "Ball height must be a positive integer. Value " << e << " given." << std::endl;
  }
}

void Ball::UpdatePosition(float elapsedTime) {
  pos_ += velocity_ * elapsedTime;
}

Ball::Ball(Vec2D position, Vec2D velocity, int width, int height) 
  : pos_(position), velocity_(velocity) {
  SetWidth(width);
  SetHeight(height);
}

Ball::Ball(Vec2D position, Vec2D velocity)
  : pos_(position), velocity_(velocity), width_(1), height_(1) {}

Ball::Ball() : width_(1), height_(1) {
  pos_ = Vec2D();
}