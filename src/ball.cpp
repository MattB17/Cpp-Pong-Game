#include "ball.h"
#include <iostream>

void Ball::setWidth(int width) {
  try {
    if (width <= 0) throw width;
    width_ = width;
  } catch (int e) {
    std::cerr << "Ball width must be a positive integer. Value " << e << " given." << std::endl;
  }
}

void Ball::setHeight(int height) {
  try {
    if (height <= 0) throw height;
    height_ = height;
  } catch (int e) {
    std::cerr << "Ball height must be a positive integer. Value " << e << " given." << std::endl;
  }
}

Ball::Ball(Vec2D position, int width, int height) : pos_(position) {
  setWidth(width);
  setHeight(height);
}

Ball::Ball() : width_(1), height_(1) {
  pos_ = Vec2D();
}