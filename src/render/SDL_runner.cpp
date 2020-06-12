#include "SDL_runner.h"
#include <iostream>

SDL_Runner::SDL_Runner() {
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL Error: " << SDL_GetError() << std::endl;
  }
}

SDL_Runner::~SDL_Runner() {
  SDL_Quit();
}