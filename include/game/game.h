#ifndef GAME_H
#define GAME_H

#include "ball.h"
#include "player.h"
#include "paddle.h"
#include "controller.h"
#include "renderer.h"
#include "contact.h"
#include <memory>

class Game {
  public:
    Game();
    void Run(Controller const &controller, Renderer &renderer);
  
  private:
    std::unique_ptr<Ball> ball_;
    std::unique_ptr<Player> user_;
    std::unique_ptr<Player> computerAI_;
  
    void Update(float elapsedTime, Renderer const &renderer);
    void HandleBallPaddleContact(Contact contact, Renderer const &renderer);
  
    Contact GetBallPaddleContact(Paddle const &paddle);
    Contact GetBallWallContact();
};

#endif