#ifndef GAME_H
#define GAME_H

#include "ball.h"
#include "player.h"
#include "paddle.h"
#include "controller.h"
#include "renderer.h"
#include "contact.h"
#include <vector>

class Game {
  public:
    Game();
    void Run(Controller const &controller, Renderer &renderer);
  
  private:
    Ball ball_;
    std::vector<Player> players_;
  
    void Update(float elapsedTime);
    Contact GetBallPaddleContact(Paddle paddle);
    Contact GetBallWallContact();
};

#endif