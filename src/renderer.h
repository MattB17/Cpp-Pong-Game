#ifndef RENDERER_H
#define RENDERER_H

#include "SDL.h"

class Renderer {
  public:
    Renderer(const std::size_t screen_width, const std::size_t screen_height);
    ~Renderer();
    
    void Render();
  
  private:
    SDL_Window *window_;
    SDL_Renderer *renderer_;
  
    const std::size_t screen_width_;
    const std::size_t screen_height_;
};

#endif