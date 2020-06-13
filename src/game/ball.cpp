#include "ball.h"
#include "constants.h"
#include <iostream>

void Ball::UpdatePosition(float elapsedTime) {
  pos_ += velocity_ * elapsedTime;
}

void Ball::HandleObjectCollision(Contact const &contact) {
  // move the ball to the edge of the object and reverse x direction
  pos_.SetX(pos_.GetX() + contact.penetration);
  velocity_.SetX(-velocity_.GetX());
  
  // change y direction if object hits top or bottom of object
  if (contact.collisionType == CollisionType::kTop) {
    velocity_.SetY(-0.75f * speed_);
  } else if (contact.collisionType == CollisionType::kBottom) {
    velocity_.SetY(0.75f * speed_);
  }
}

void Ball::HandleWallCollision(Contact const &contact) {
  if ((contact.collisionType == CollisionType::kTop) || 
      (contact.collisionType == CollisionType::kBottom)) {
    // if ball hit top or bottom, move to edge of the wall
    // then send in the opposite y direction
    pos_.SetY(pos_.GetY() + contact.penetration);
    velocity_.SetY(-velocity_.GetY());
  } else if (contact.collisionType == CollisionType::kLeft) {
    // if hit left, move to origin and send left
    pos_ = Vec2D(kScreenWidth / 2.0f, kScreenHeight / 2.0f);
    velocity_ = Vec2D(speed_, 0.25f * speed_);
  } else if (contact.collisionType == CollisionType::kRight) {
    // if hit right, move to origin and send right
    pos_ = Vec2D(kScreenWidth / 2.0f, kScreenHeight / 2.0f);
    velocity_ = Vec2D(-speed_, 0.25f * speed_);
  }
}
    
Ball::Ball(Vec2D position, Vec2D velocity, float speed, int width, int height) 
  : pos_(position), velocity_(velocity), speed_(speed), GameObject(width, height) {
}

Ball::Ball(Vec2D position, Vec2D velocity, float speed)
  : pos_(position), velocity_(velocity), speed_(speed), GameObject() {}