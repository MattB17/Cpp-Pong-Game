#ifndef BALL_H
#define BALL_H

#include "vec2d.h"
#include "contact.h"

class Ball {
  public:
    Ball();
    Ball(Vec2D position, Vec2D velocity);
    Ball(Vec2D position, Vec2D velocity, int width, int height);
    
    Vec2D GetPosition() { return pos_; }
    void UpdatePosition(float elapsedTime);
    Vec2D GetVelocity() { return velocity_; }
    int GetWidth() { return width_; }
    void SetWidth(int width);
    int GetHeight() { return height_; }
    void SetHeight(int height);
  
    void HandleObjectCollision(Contact const &contact);
    void HandleWallCollision(Contact const &contact);
  
  private:
    Vec2D pos_;
    Vec2D velocity_;
    int width_;
    int height_;
};

#endif