#ifndef PADDLE_H
#define PADDLE_H

#include "vec2d.h"

class Paddle {
  public:
    Paddle(Vec2D position) : pos_(position), width_(1), height_(1) {}
    Paddle(Vec2D position, int width, int height);
  
    Vec2D getPosition() { return pos_; }
    void setYPosition(float y);
    int getWidth() { return width_; }
    void setWidth(int width);
    int getHeight() { return height_; }
    void setHeight(int height);
  
  private:
    Vec2D pos_;
    int width_;
    int height_;
};

#endif