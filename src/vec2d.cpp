#include "vec2d.h"
#include <iostream>

Vec2D Vec2D::operator+(Vec2D const &other) {
  return Vec2D(x_ + other.GetX(),
               y_ + other.GetY());
}

Vec2D& Vec2D::operator+=(Vec2D const &other) {
  x_ += other.GetX();
  y_ += other.GetY();
  
  return *this;
}

Vec2D Vec2D::operator*(float scalar) {
  return Vec2D(x_ * scalar,
               y_ * scalar);
}