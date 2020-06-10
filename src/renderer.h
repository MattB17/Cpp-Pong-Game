#ifndef RENDERER_H
#define RENDERER_H

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "ball.h"
#include "vec2d.h"
#include "paddle.h"
#include "player.h"
#include <vector>

class Renderer {
  public:
    Renderer();
    ~Renderer();
    
    void Render(Ball const &ball, std::vector<Player> const &players);
  
    Mix_Chunk *wallHitSound_;
    Mix_Chunk *objectHitSound_;
  
  private:
    SDL_Window *window_;
    SDL_Renderer *renderer_;
    TTF_Font *scoreFont_;
    SDL_Surface *surface_{};
    SDL_Texture *texture_{};
  
    const std::size_t screen_width_;
    const std::size_t screen_height_;
    
    void DrawBall(Ball ball);
    void DrawPaddle(Paddle paddle);
    
    void RenderPlayer(const Player &player);
};

#endif