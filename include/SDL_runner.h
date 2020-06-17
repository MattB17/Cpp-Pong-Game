#ifndef SDL_RUNNER_H
#define SDL_RUNNER_H

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"

class SDL_Runner {
  public:
    SDL_Runner();
    ~SDL_Runner();
  
    // cannot copy or move an SDL_Runner
    SDL_Runner(const SDL_Runner& source) = delete;
    SDL_Runner& operator=(const SDL_Runner& source) = delete;
    SDL_Runner(SDL_Runner&& source) = delete;
    SDL_Runner& operator=(SDL_Runner&& source) = delete;
};

#endif