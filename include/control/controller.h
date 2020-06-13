#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "player.h"
#include "paddle.h"
#include <vector>

class Controller {
  public:
    Controller() {};
    void CheckForQuit(bool &running) const;
    void HandleInput(bool &running, std::vector<Player> &players) const;
  
  private:
    void ChangePaddleDirection(Player &player, Paddle::Direction input) const;
};

#endif