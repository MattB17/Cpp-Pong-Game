#include "ball.h"
#include "constants.h"
#include <iostream>

void Ball::HandleObjectCollision(Contact const &contact) {
  // move the ball to the edge of the object and reverse x direction
  pos_->SetX(pos_->GetX() + contact.penetration);
  velocity_->SetX(-velocity_->GetX());
  
  // change y direction if object hits top or bottom of object
  if (contact.collisionType == CollisionType::kTop) {
    velocity_->SetY(-0.75f * speed_);
  } else if (contact.collisionType == CollisionType::kBottom) {
    velocity_->SetY(0.75f * speed_);
  }
}

void Ball::HandleWallCollision(Contact const &contact) {
  if ((contact.collisionType == CollisionType::kTop) || 
      (contact.collisionType == CollisionType::kBottom)) {
    // if ball hit top or bottom, move to edge of the wall
    // then send in the opposite y direction
    pos_->SetY(pos_->GetY() + contact.penetration);
    velocity_->SetY(-velocity_->GetY());
  } else if (contact.collisionType == CollisionType::kLeft ||
             contact.collisionType == CollisionType::kRight) {
    // if hit side, move to origin and move back towards that side
    pos_->SetX(kScreenWidth / 2.0f);
    pos_->SetY(kScreenHeight / 2.0f);
    int direction = 1 - (2 * (contact.collisionType == CollisionType::kRight));
    velocity_->SetX(direction * speed_);
    velocity_->SetY(0.25f * speed_);
  }
}
    
Ball::Ball(std::unique_ptr<Vec2D> position, 
           std::unique_ptr<Vec2D> velocity, 
           float speed, int width, int height) 
  : speed_(speed), GameObject(width, height) {
    pos_ = std::move(position);
    velocity_ = std::move(velocity);
}

Ball::Ball(std::unique_ptr<Vec2D> position, 
           std::unique_ptr<Vec2D> velocity, float speed)
  : speed_(speed), GameObject() {
    pos_ = std::move(position);
    velocity_ = std::move(velocity);
}