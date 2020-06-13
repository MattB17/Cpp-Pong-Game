#include "game_object.h"
#include <iostream>

GameObject::GameObject() : width_(1), height_(1) {}

GameObject::GameObject(int width, int height) {
    SetWidth(width);
    SetHeight(height);
}

void GameObject::SetWidth(int width) {
  try {
    if (width <= 0) throw width;
    width_ = width;
  } catch (int e) {
    std::cerr << "Width must be a positive integer. Value " << e << " given" << std::endl;
  }
}

void GameObject::SetHeight(int height) {
  try {
    if (height <= 0) throw height;
    height_ = height;
  } catch (int e) {
    std::cerr << "Height must be a positive integer. Value " << e << " given" << std::endl;
  }
}