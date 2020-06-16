#include "game_object.h"
#include <iostream>

GameObject::GameObject() : width_(1), height_(1) {}

GameObject::GameObject(int width, int height) {
    SetWidth(width);
    SetHeight(height);
}

GameObject::GameObject(const GameObject& source) {
  *pos_ = *(source.pos_);
  *velocity_ = *(source.velocity_);
  width_ = source.width_;
  height_ = source.height_;
}

GameObject& GameObject::operator=(const GameObject& source) {
  if (*this != source) {
    *pos_ = *(source.pos_);
    *velocity_ = *(source.velocity_);
    width_ = source.width_;
    height_ = source.height_;
  }
  return *this;
}

GameObject::GameObject(GameObject&& source) {
  pos_ = std::move(source.pos_);
  velocity_ = std::move(source.velocity_);
  width_ = source.width_;
  height_ = source.height_;
  
  source.pos_ = nullptr;
  source.velocity_ = nullptr;
  width_ = 0;
  height_ = 0;
}

GameObject& GameObject::operator=(GameObject&& source) {
  if (*this != source) {
    pos_ = std::move(source.pos_);
    velocity_ = std::move(source.velocity_);
    width_ = source.width_;
    height_ = source.height_;
    
    source.pos_ = nullptr;
    source.velocity_ = nullptr;
    width_ = 0;
    height_ = 0;
  }
  return *this;
}

bool GameObject::operator==(const GameObject& other) {
  return ((*pos_ == *(other.pos_)) &&
          (*velocity_ == *(other.velocity_)) &&
          (width_ == other.width_) &&
          (height_ == other.height_));
}

bool GameObject::operator!=(const GameObject& other) {
  return ((*pos_ != *(other.pos_)) ||
          (*velocity_ != *(other.velocity_)) ||
          (width_ != other.width_) ||
          (height_ != other.height_));
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

void GameObject::UpdatePosition(float elapsedTime) {
  *pos_ += *velocity_ * elapsedTime;
}