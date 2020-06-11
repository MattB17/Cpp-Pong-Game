#include "controller.h"
#include "constants.h"
#include <iostream>
#include "SDL.h"

void Controller::HandleInput(bool &running, std::vector<Player> &players) const {
  SDL_Event event;
  // continuously poll to see if user has quit
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      running = false;
    } else if (event.type == SDL_KEYDOWN) {
      switch(event.key.keysym.sym) {
        case SDLK_UP:
          ChangePaddleDirection(players.at(1), Paddle::Direction::kUp);
          break;
        case SDLK_DOWN:
          ChangePaddleDirection(players.at(1), Paddle::Direction::kDown);
          break;
        case SDLK_w:
          ChangePaddleDirection(players.at(0), Paddle::Direction::kUp);
          break;
        case SDLK_s:
          ChangePaddleDirection(players.at(0), Paddle::Direction::kDown);
          break;
      }
    } else if (event.type == SDL_KEYUP) {
      switch(event.key.keysym.sym) {
        case SDLK_UP:
        case SDLK_DOWN:
          ChangePaddleDirection(players.at(1), Paddle::Direction::kNone);
          break;
        case SDLK_w:
        case SDLK_s:
          ChangePaddleDirection(players.at(0), Paddle::Direction::kNone);
          break;
      }
    }
  }
}

void Controller::ChangePaddleDirection(Player &player, Paddle::Direction input) const {
  if (input == Paddle::Direction::kUp) {
    player.UpdatePaddleVelocityY(-kPaddleSpeed);
  } else if (input == Paddle::Direction::kDown) {
    player.UpdatePaddleVelocityY(kPaddleSpeed);
  } else {
    player.UpdatePaddleVelocityY(0.0f);
  }
}