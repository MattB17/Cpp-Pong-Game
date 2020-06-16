#ifndef TEXT_HANDLER_H
#define TEXT_HANDLER_H

#include "SDL_runner.h"
#include "player.h"
#include "vec2d.h"
#include <string>
#include <memory>
#include <mutex>

class TextHandler {
  public:
    TextHandler(std::shared_ptr<SDL_Runner> runner);
    ~TextHandler();
      
    void DrawPlayerScore(SDL_Renderer *renderer, Player const &player);
    void DrawCount(SDL_Renderer *renderer, int count, Vec2D const &position);
  
  private:
    std::shared_ptr<SDL_Runner> runner_;
    
    TTF_Font *scoreFont_;
    TTF_Font *countFont_;
    SDL_Surface *surface_{};
    SDL_Texture *texture_{};
  
    void DrawText(SDL_Renderer *renderer, Vec2D const &position);
};

#endif