#ifndef PADDLE_H
#define PADDLE_H

#include "game_object.h"
#include "vec2d.h"
#include <memory>

class Paddle : public GameObject {
  public:
    enum class Direction { kUp, kDown, kNone };
  
    Paddle(std::unique_ptr<Vec2D> position, 
           std::unique_ptr<Vec2D> velocity);
    Paddle(std::unique_ptr<Vec2D> position, 
           std::unique_ptr<Vec2D> velocity, 
           int width, int height);
  
    const Vec2D &GetPosition() const { return *pos_; }
    const Vec2D GetVelocity() const { return *velocity_; }
    void UpdatePosition(float elapsedTime);
    void UpdateVelocityY(float y);
  
  private:
    std::unique_ptr<Vec2D> pos_;
    std::unique_ptr<Vec2D> velocity_;
};

#endif