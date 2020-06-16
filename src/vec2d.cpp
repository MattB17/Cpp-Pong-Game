#include "vec2d.h"
#include <iostream>

bool Vec2D::operator==(const Vec2D& other) {
  return ((x_ == other.GetX()) && (y_ == other.GetY()));
}

bool Vec2D::operator!=(const Vec2D& other) {
  return ((x_ != other.GetX()) || (y_ != other.GetY()));
}

Vec2D Vec2D::operator+(const Vec2D& other) {
  return Vec2D(x_ + other.GetX(),
               y_ + other.GetY());
}

Vec2D& Vec2D::operator+=(const Vec2D& other) {
  x_ += other.GetX();
  y_ += other.GetY();
  
  return *this;
}

Vec2D Vec2D::operator*(float scalar) {
  return Vec2D(x_ * scalar,
               y_ * scalar);
}