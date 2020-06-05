#ifndef RENDERER_H
#define RENDERER_H

#include "SDL.h"
#include "ball.h"
#include "vec2d.h"

class Renderer {
  public:
    Renderer();
    ~Renderer();
    
    void Render(Ball ball);
  
  private:
    SDL_Window *window_;
    SDL_Renderer *renderer_;
  
    const std::size_t screen_width_;
    const std::size_t screen_height_;
    
    SDL_Rect drawBall(Ball ball);
};

#endif