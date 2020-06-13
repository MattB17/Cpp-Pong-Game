#include "paddle.h"
#include "constants.h"

Paddle::Paddle(Vec2D position, Vec2D velocity) 
  : pos_(position), velocity_(velocity), GameObject() {
}

Paddle::Paddle(Vec2D position, Vec2D velocity, int width, int height) 
  : pos_(position), velocity_(velocity), GameObject(width, height) {
}

void Paddle::UpdatePosition(float elapsedTime) {
  pos_ += velocity_ * elapsedTime;
  if (pos_.GetY() < 0) {
    pos_.SetY(0);
  } else if (pos_.GetY() > (kScreenHeight - GetHeight())) {
    pos_.SetY(kScreenHeight - GetHeight());
  }
}

void Paddle::UpdateVelocityY(float y) {
  velocity_.SetY(y);
}
