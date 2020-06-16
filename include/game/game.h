#ifndef GAME_H
#define GAME_H

#include "ball.h"
#include "player.h"
#include "paddle.h"
#include "controller.h"
#include "renderer.h"
#include "contact.h"
#include <memory>
#include <mutex>

class Game {
  public:
    Game();
    ~Game() {}
  
    // cannot copy or move a game
    Game(const Game& source) = delete;
    Game& operator=(const Game& source) = delete;
    Game(Game&& source) = delete;
    Game& operator=(Game&& source) = delete;
  
    void Run(const Controller& controller, Renderer &renderer);
  
  private:
    std::unique_ptr<Ball> ball_;
    std::unique_ptr<Player> user_;
    std::unique_ptr<Player> computerAI_;
  
    std::mutex ballMtx_;
  
    void Update(float elapsedTime, const Renderer& renderer);
    void UpdateAI(float elapsedTime);
    void HandleBallPaddleContact(const Contact& contact, const Renderer& renderer);
  
    Contact GetBallPaddleContact(const Paddle& paddle);
    Contact GetBallWallContact();
};

#endif