#ifndef PLAYER_H
#define PLAYER_H

#include "vec2d.h"
#include "paddle.h"
#include <string>

class Player {
  public:
    Player(std::string name, Paddle paddle, Vec2D scoreDisplayPos);
  
    std::string GetName() { return name_; }
    Paddle GetPaddle() { return paddle_; }
    Vec2D GetScoreDisplayPos() { return scoreDisplayPos_; }
    int GetScore() { return score_; }
    
    void UpdatePaddlePosition(float elapsedTime);
    void UpdatePaddleVelocityY(float y);
    void IncrementScore() { ++score_; }
    std::string GetScoreString() { return std::to_string(score_); }
    
  private:
    std::string name_;
    Paddle paddle_;
    Vec2D scoreDisplayPos_;
    int score_;
};

#endif