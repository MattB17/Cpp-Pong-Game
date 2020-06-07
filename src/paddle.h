#ifndef PADDLE_H
#define PADDLE_H

#include "vec2d.h"

class Paddle {
  public:
    enum class Direction { kUp, kDown, kNone };
  
    Paddle(Vec2D position, Vec2D velocity);
    Paddle(Vec2D position, Vec2D velocity, int width, int height);
  
    Vec2D GetPosition() { return pos_; }
    void UpdatePosition(float elapsedTime);
    Vec2D GetVelocity() { return velocity_; }
    void UpdateVelocityY(float y); 
    int GetWidth() { return width_; }
    void SetWidth(int width);
    int GetHeight() { return height_; }
    void SetHeight(int height);
  
  private:
    Vec2D pos_;
    Vec2D velocity_;
    int width_;
    int height_;
};

#endif