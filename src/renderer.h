#ifndef RENDERER_H
#define RENDERER_H

#include "SDL.h"
#include "SDL_ttf.h"
#include "ball.h"
#include "vec2d.h"
#include "paddle.h"
#include "score.h"
#include <vector>

class Renderer {
  public:
    Renderer();
    ~Renderer();
    
    void Render(Ball ball, std::vector<Paddle> paddles, std::vector<Score> scores);
  
  private:
    SDL_Window *window_;
    SDL_Renderer *renderer_;
    TTF_Font *scoreFont_;
    SDL_Surface *surface_{};
    SDL_Texture *texture_{};
  
    const std::size_t screen_width_;
    const std::size_t screen_height_;
    
    void drawBall(Ball ball);
    void drawPaddle(Paddle paddle);
    void drawScore(Score score);
};

#endif