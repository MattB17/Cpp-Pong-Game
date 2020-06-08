#ifndef BALL_H
#define BALL_H

#include "vec2d.h"

class Ball {
  public:
    Ball();
    Ball(Vec2D position, Vec2D velocity);
    Ball(Vec2D position, Vec2D velocity, int width, int height);
    
    Vec2D GetPosition() { return pos_; }
    void UpdatePosition(float elapsedTime);
    int GetWidth() { return width_; }
    void SetWidth(int width);
    int GetHeight() { return height_; }
    void SetHeight(int height);
  
    void NegateVelocity();
  
  private:
    Vec2D pos_;
    Vec2D velocity_;
    int width_;
    int height_;
};

#endif