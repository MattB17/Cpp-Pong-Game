#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "vec2d.h"
#include "ball.h"
#include "controller.h"
#include "renderer.h"

class Game {
  public:
    Game(int ballWidth, int ballHeight,
         std::size_t screenWidth, std::size_t screenHeight);
    void Run(Controller const &controller, Renderer &renderer);
  
  private:
    Ball ball_;
  
    void Update();
};

#endif