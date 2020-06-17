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
#include <mutex>

class Renderer {
  public:
    Renderer(std::shared_ptr<SDL_Runner> runner);
    ~Renderer();
  
    // no copying or moving renderers
    Renderer(const Renderer& source) = delete;
    Renderer& operator=(const Renderer& source) = delete;
    Renderer(Renderer&& source) = delete;
    Renderer& operator=(Renderer&& source) = delete;
    
    void Render(const Ball & ball, const Player& user, const Player& computerAI);
    void RenderCountPage(int count, const Player& user, const Player& computerAI);
    
    void PlayObjectHitSound() const;
    void PlayWallHitSound() const;
  
  private:
    // owned resources
    std::unique_ptr<TextHandler> textHandler_;
    std::unique_ptr<AudioHandler> audioHandler_;
    SDL_Window *window_;
    SDL_Renderer *renderer_;
    const Vec2D center_;
  
    // shared resource
    std::shared_ptr<SDL_Runner> runner_;
  
    std::mutex renderMtx_;
    
    void RenderGameBoard(const Player& user, const Player& computerAI);
    void RenderTable();
    void DrawBall(const Ball& ball);
    void DrawPaddle(const Paddle& paddle);
    void RenderPlayer(const Player& player);
};

#endif