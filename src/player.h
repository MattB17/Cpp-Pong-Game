#ifndef PLAYER_H
#define PLAYER_H

#include "vec2d.h"
#include "paddle.h"
#include <string>

class Player {
  public:
    Player(std::string name, Paddle paddle, Vec2D scoreDisplayPos);
  
    std::string getName() { return name_; }
    Paddle getPaddle() { return paddle_; }
    Vec2D getScoreDisplayPos() { return scoreDisplayPos_; }
    int getScore() { return score_; }
    
    void incrementScore() { ++score_; }
    std::string getScoreString() { return std::to_string(score_); }
    
  private:
    std::string name_;
    Paddle paddle_;
    Vec2D scoreDisplayPos_;
    int score_;
};

#endif