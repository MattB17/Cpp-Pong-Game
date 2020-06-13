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
    
    const Vec2D &GetPosition() const { return *pos_; }
    const Vec2D &GetVelocity() const { return *velocity_; }
    void UpdatePosition(float elapsedTime);
  
    void HandleObjectCollision(Contact const &contact);
    void HandleWallCollision(Contact const &contact);
  
  private:
    std::unique_ptr<Vec2D> pos_;
    std::unique_ptr<Vec2D> velocity_;
    float speed_;
};

#endif