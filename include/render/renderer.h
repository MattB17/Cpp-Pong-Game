#ifndef RENDERER_H
#define RENDERER_H

#include "SDL_runner.h"
#include "text_handler.h"
#include "audio_handler.h"
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
    
    void Render(Ball const &ball, Player const &user, Player const &computerAI);
    void RenderCountPage(int count, Player const &user, Player const &computerAI);
    
    void PlayObjectHitSound() const;
    void PlayWallHitSound() const;
  
  private:
    std::unique_ptr<TextHandler> textHandler_;
    std::unique_ptr<AudioHandler> audioHandler_;
  
    std::shared_ptr<SDL_Runner> runner_;
    SDL_Window *window_;
    SDL_Renderer *renderer_;
  
    const Vec2D center_;
    
    void RenderGameBoard(Player const &user, Player const &computerAI);
    void RenderTable();
    void DrawBall(Ball const &ball);
    void DrawPaddle(Paddle const &paddle);
    void RenderPlayer(Player const &player);
};

#endif