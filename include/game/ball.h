#ifndef BALL_H
#define BALL_H

#include "game_object.h"
#include "vec2d.h"
#include "contact.h"

class Ball : public GameObject {
  public:
    Ball(Vec2D position, Vec2D velocity, float speed);
    Ball(Vec2D position, Vec2D velocity, float speed, int width, int height);
    
    Vec2D GetPosition() { return pos_; }
    Vec2D GetVelocity() { return velocity_; }
    void UpdatePosition(float elapsedTime);
  
    void HandleObjectCollision(Contact const &contact);
    void HandleWallCollision(Contact const &contact);
  
  private:
    Vec2D pos_;
    Vec2D velocity_;
    float speed_;
};

#endif