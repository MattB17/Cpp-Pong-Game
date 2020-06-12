#ifndef RENDERER_H
#define RENDERER_H

#include "SDL_runner.h"
#include "text_handler.h"
#include "ball.h"
#include "vec2d.h"
#include "paddle.h"
#include "player.h"
#include <vector>
#include <memory>

class Renderer {
  public:
    Renderer();
    ~Renderer();
    
    void Render(Ball const &ball, std::vector<Player> const &players);
  
    Mix_Chunk *wallHitSound_;
    Mix_Chunk *objectHitSound_;
  
  private:
    std::unique_ptr<TextHandler> textHandler_;
  
    std::shared_ptr<SDL_Runner> runner_;
    SDL_Window *window_;
    SDL_Renderer *renderer_;
  
    const std::size_t screen_width_;
    const std::size_t screen_height_;
    
    void RenderTable();
    void DrawBall(Ball ball);
    void DrawPaddle(Paddle paddle);
    void RenderPlayer(Player const &player);
};

#endif