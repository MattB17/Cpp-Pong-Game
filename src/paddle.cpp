#include "paddle.h"
#include <iostream>

void Paddle::setYPosition(float y) {
  pos_.setY(y);
}

void Paddle::setWidth(int width) {
  try {
    if (width <= 0) throw width;
    width_ = width;
  } catch (int e) {
    std::cerr << "Paddle width must be a positive integer. Value " << e << " given" << std::endl;
  }
}

void Paddle::setHeight(int height) {
  try {
    if (height <= 0) throw height;
    height_ = height;
  } catch (int e) {
    std::cerr << "Paddle height must be a positive integer. Value " << e << " given" << std::endl;
  }
}

Paddle::Paddle(Vec2D position, int width, int height) : pos_(position) {
  setWidth(width);
  setHeight(height);
}