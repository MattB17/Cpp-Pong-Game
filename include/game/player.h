#ifndef PLAYER_H
#define PLAYER_H

#include "vec2d.h"
#include "paddle.h"
#include <string>
#include <memory>

class Player {
  public:
    Player(std::string name, 
           std::unique_ptr<Paddle> paddle, 
           std::unique_ptr<Vec2D> scoreDisplayPos);
    Player(std::string name, float paddle_x, float paddle_y, float score_x);
    ~Player() {}
  
    Player(const Player& source);
    Player& operator=(const Player& source);
    Player(Player&& source);
    Player& operator=(Player&& source);
  
    bool operator==(const Player& other);
    bool operator!=(const Player& other);
  
    std::string GetName() const { return name_; }
    const Paddle &GetPaddle() const { return *paddle_; }
    const Vec2D &GetScoreDisplayPos() const { return *scoreDisplayPos_; }
    int GetScore() { return score_; }
    
    void UpdatePaddlePosition(float elapsedTime);
    void UpdatePaddleVelocityY(float y);
    void IncrementScore() { ++score_; }
    const std::string GetScoreString() const { return std::to_string(score_); }
    
  private:
    std::string name_;
    std::unique_ptr<Paddle> paddle_;
    std::unique_ptr<Vec2D> scoreDisplayPos_;
    int score_;
};

#endif