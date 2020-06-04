#include "controller.h"
#include <iostream>
#include "SDL.h"

void Controller::HandleInput(bool &running) const {
  SDL_Event e;
  // continuously poll to see if user has quit
  while (SDL_PollEvent(&e)) {
    if (e.type = SDL_QUIT) {
      running = false;
    }
  }
}