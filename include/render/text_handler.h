#ifndef TEXT_HANDLER_H
#define TEXT_HANDLER_H

#include "SDL_runner.h"
#include "player.h"
#include <memory>

class TextHandler {
  public:
    TextHandler(std::shared_ptr<SDL_Runner> runner);
    ~TextHandler();
      
    void DrawPlayerScore(SDL_Renderer *renderer, Player const &player);
  
  private:
    std::shared_ptr<SDL_Runner> runner_;
    
    TTF_Font *scoreFont_;
    SDL_Surface *surface_{};
    SDL_Texture *texture_{};
};

#endif