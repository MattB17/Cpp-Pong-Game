#ifndef BALL_H
#define BALL_H

#include "game_object.h"
#include "vec2d.h"
#include "contact.h"
#include <memory>

class Ball : public GameObject {
  public:
    Ball(std::unique_ptr<Vec2D> position, 
         std::unique_ptr<Vec2D> velocity, 
         float speed);
    Ball(std::unique_ptr<Vec2D> position, 
         std::unique_ptr<Vec2D> velocity, 
         float speed, int width, int height);
  
    void HandleObjectCollision(const Contact& contact);
    void HandleWallCollision(const Contact& contact);
  
  private:
    float speed_;
};

#endif