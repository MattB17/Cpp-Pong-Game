#include "paddle.h"
#include "constants.h"

Paddle::Paddle(std::unique_ptr<Vec2D> position, 
               std::unique_ptr<Vec2D> velocity) 
  : GameObject() {
    pos_ = std::move(position);
    velocity_ = std::move(velocity);
}

Paddle::Paddle(std::unique_ptr<Vec2D> position, 
               std::unique_ptr<Vec2D> velocity, 
               int width, int height) 
  : GameObject(width, height) {
    pos_ = std::move(position);
    velocity_ = std::move(velocity);
}

void Paddle::UpdatePosition(float elapsedTime) {
  GameObject::UpdatePosition(elapsedTime);
  if (pos_->GetY() < 0) {
    pos_->SetY(0);
  } else if (pos_->GetY() > (kScreenHeight - GetHeight())) {
    pos_->SetY(kScreenHeight - GetHeight());
  }
}

void Paddle::UpdateVelocityY(float y) {
  velocity_->SetY(y);
}
