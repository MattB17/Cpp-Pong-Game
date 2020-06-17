#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "player.h"
#include "paddle.h"
#include "SDL_runner.h"
#include <vector>
#include <memory>

class Controller {
  public:
    Controller(std::shared_ptr<SDL_Runner> runner);
    ~Controller() {};
  
    // cannot copy or move a controller
    Controller(const Controller& source) = delete;
    Controller& operator=(const Controller& source) = delete;
    Controller(Controller&& source) = delete;
    Controller& operator=(const Controller&& source) = delete;
  
    void CheckForQuit(bool &running) const;
    void HandleInput(bool &running, Player &user) const;
  
  private:
    std::shared_ptr<SDL_Runner> runner_;
  
    void ChangePaddleDirection(Player &player, Paddle::Direction input) const;
};

#endif