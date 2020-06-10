#ifndef GAME_H
#define GAME_H

#include "ball.h"
#include "player.h"
#include "paddle.h"
#include "controller.h"
#include "renderer.h"
#include "contact.h"
#include <vector>
#include <memory>

class Game {
  public:
    Game();
    void Run(Controller const &controller, Renderer &renderer);
  
  private:
    std::unique_ptr<Ball> ball_;
    std::vector<Player> players_;
  
    void Update(float elapsedTime, Renderer const &renderer);
    Contact GetBallPaddleContact(Paddle paddle);
    Contact GetBallWallContact();
};

#endif