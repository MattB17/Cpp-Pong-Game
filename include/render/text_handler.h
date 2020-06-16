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
  
    // no copying or moving text handlers
    TextHandler(const TextHandler& source) = delete;
    TextHandler& operator=(const TextHandler& source) = delete;
    TextHandler(TextHandler&& source) = delete;
    TextHandler& operator=(TextHandler&& source) = delete;
      
    void DrawPlayerScore(SDL_Renderer *renderer, const Player& player);
    void DrawCount(SDL_Renderer *renderer, int count, const Vec2D& position);
  
  private:
    std::shared_ptr<SDL_Runner> runner_;
    
    TTF_Font *scoreFont_;
    TTF_Font *countFont_;
    SDL_Surface *surface_{};
    SDL_Texture *texture_{};
  
    void DrawText(SDL_Renderer *renderer, const Vec2D& position);
};

#endif