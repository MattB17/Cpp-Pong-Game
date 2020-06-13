#ifndef PADDLE_H
#define PADDLE_H

#include "game_object.h"
#include "vec2d.h"

class Paddle : public GameObject {
  public:
    enum class Direction { kUp, kDown, kNone };
  
    Paddle(Vec2D position, Vec2D velocity);
    Paddle(Vec2D position, Vec2D velocity, int width, int height);
  
    Vec2D GetPosition() { return pos_; }
    Vec2D GetVelocity() { return velocity_; }
    void UpdatePosition(float elapsedTime);
    void UpdateVelocityY(float y);
  
  private:
    Vec2D pos_;
    Vec2D velocity_;
};

#endif