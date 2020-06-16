#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "player.h"
#include "paddle.h"
#include <vector>

class Controller {
  public:
    Controller() {};
    ~Controller() {};
  
    // cannot copy or move a controller
    Controller(const Controller& source) = delete;
    Controller& operator=(const Controller& source) = delete;
    Controller(Controller&& source) = delete;
    Controller& operator=(const Controller&& source) = delete;
  
    void CheckForQuit(bool &running) const;
    void HandleInput(bool &running, Player &user) const;
  
  private:
    void ChangePaddleDirection(Player &player, Paddle::Direction input) const;
};

#endif