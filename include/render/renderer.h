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
    
    void Render(Ball const &ball, std::vector<Player> const &players);
    void RenderCountPage(int count, std::vector<Player> const &players);
    
    void PlayObjectHitSound() const;
    void PlayWallHitSound() const;
  
  private:
    std::unique_ptr<TextHandler> textHandler_;
    std::unique_ptr<AudioHandler> audioHandler_;
  
    std::shared_ptr<SDL_Runner> runner_;
    SDL_Window *window_;
    SDL_Renderer *renderer_;
  
    const Vec2D center_;
    
    void RenderGameBoard(std::vector<Player> const &players);
    void RenderTable();
    void DrawBall(Ball ball);
    void DrawPaddle(Paddle paddle);
    void RenderPlayer(Player const &player);
};

#endif