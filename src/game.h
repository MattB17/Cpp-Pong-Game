#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "vec2d.h"
#include "ball.h"
#include "paddle.h"
#include "score.h"
#include "controller.h"
#include "renderer.h"
#include <vector>

class Game {
  public:
    Game();
    void Run(Controller const &controller, Renderer &renderer);
  
  private:
    Ball ball_;
    std::vector<Paddle> paddles_;
    std::vector<Score> scores_;
  
    void Update();
};

#endif