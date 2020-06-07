#ifndef SCORE_H
#define SCORE_H

#include "vec2d.h"
#include <string>

class Score {
  public:
    Score(Vec2D displayPosition);
    
    Vec2D getDisplayPosition() { return displayPos_; }
    int getScore() { return score_; }
    void incrementScore() { ++score_; }
    std::string getScoreString() { return std::to_string(score_); }
  
  private:
    Vec2D displayPos_;
    int score_;
};

#endif