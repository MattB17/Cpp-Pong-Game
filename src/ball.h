#ifndef BALL_H
#define BALL_H

#include "vec2d.h"

class Ball {
  public:
    Ball();
    Ball(Vec2D position) : pos_(position), width_(1), height_(1) {}
    Ball(Vec2D position, int width, int height);
    
    Vec2D GetPosition() { return pos_; }
    void SetPosition(Vec2D position) { pos_ = position; }
    int GetWidth() { return width_; }
    void SetWidth(int width);
    int GetHeight() { return height_; }
    void SetHeight(int height);
  
  private:
    Vec2D pos_;
    int width_;
    int height_;
};

#endif