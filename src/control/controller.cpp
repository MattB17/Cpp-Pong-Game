#include "controller.h"
#include "constants.h"
#include <iostream>
#include "SDL.h"

void Controller::CheckForQuit(bool &running) const {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      running = false;
    }
  }
}

void Controller::HandleInput(bool &running, Player &user, Player &computerAI) const {
  SDL_Event event;
  // continuously poll
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      // set running to false if user quit
      running = false;
    } else if (event.type == SDL_KEYDOWN) {
      switch(event.key.keysym.sym) {
        case SDLK_UP:
          ChangePaddleDirection(computerAI, Paddle::Direction::kUp);
          break;
        case SDLK_DOWN:
          ChangePaddleDirection(computerAI, Paddle::Direction::kDown);
          break;
        case SDLK_w:
          ChangePaddleDirection(user, Paddle::Direction::kUp);
          break;
        case SDLK_s:
          ChangePaddleDirection(user, Paddle::Direction::kDown);
          break;
      }
    } else if (event.type == SDL_KEYUP) {
      switch(event.key.keysym.sym) {
        case SDLK_UP:
        case SDLK_DOWN:
          ChangePaddleDirection(computerAI, Paddle::Direction::kNone);
          break;
        case SDLK_w:
        case SDLK_s:
          ChangePaddleDirection(user, Paddle::Direction::kNone);
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