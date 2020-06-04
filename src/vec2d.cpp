#include "vec2d.h"
#include <iostream>

void Vec2D::setX(float x) {
  try {
    if (x < 0.0f) throw x;
    x_ = x;
  } catch (float e) {
    std::cerr << "x value of Vec2D must be at least 0, value " << e << " given." << std::endl;
  }
}

void Vec2D::setY(float y) {
  try {
    if (y < 0.0f) throw y;
    y_ = y;
  } catch (float e) {
    std::cerr << "y value of Vec2D must be at least 0, value " << e << " given." << std::endl;
  }
}

Vec2D::Vec2D(float x, float y) {
  Vec2D::setX(x);
  Vec2D::setY(y);
}

Vec2D Vec2D::operator+(Vec2D const &other) {
  return Vec2D(x_ + other.getX(),
               y_ + other.getY());
}

Vec2D& Vec2D::operator+=(Vec2D const &other) {
  x_ += other.getX();
  y_ += other.getY();
  
  return *this;
}

Vec2D Vec2D::operator*(float scalar) {
  return Vec2D(x_ * scalar,
               y_ * scalar);
}