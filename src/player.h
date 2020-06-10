#ifndef PLAYER_H
#define PLAYER_H

#include "vec2d.h"
#include "paddle.h"
#include <string>
#include <memory>

class Player {
  public:
    Player(std::string name, 
           Paddle paddle, 
           std::unique_ptr<Vec2D> scoreDisplayPos);
  
    std::string GetName() const { return name_; }
    Paddle GetPaddle() const { return paddle_; }
    const Vec2D &GetScoreDisplayPos() const { return *scoreDisplayPos_; }
    const int GetScore() const { return *score_; }
    
    void UpdatePaddlePosition(float elapsedTime);
    void UpdatePaddleVelocityY(float y);
    void IncrementScore() { ++(*score_); }
    std::string GetScoreString() const { return std::to_string(*score_); }
    
  private:
    std::string name_;
    Paddle paddle_;
    std::unique_ptr<Vec2D> scoreDisplayPos_;
    std::unique_ptr<int> score_;
};

#endif