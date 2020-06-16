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
  
    void UpdatePosition(float elapsedTime);
    void UpdateVelocityY(float y);
};

#endif