#ifndef GAME_H
#define GAME_H

#include "ball.h"
#include "player.h"
#include "controller.h"
#include "renderer.h"
#include <vector>

class Game {
  public:
    Game();
    void Run(Controller const &controller, Renderer &renderer);
  
  private:
    Ball ball_;
    std::vector<Player> players_;
  
    void Update();
};

#endif