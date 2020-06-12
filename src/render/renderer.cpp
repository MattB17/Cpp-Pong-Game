#include "renderer.h"
#include "constants.h"
#include <iostream>
#include <string>
#include <stdlib.h>

Renderer::Renderer()
  : screen_width_(kScreenWidth), screen_height_(kScreenHeight) {
    // Run SDL
    runner_ = std::make_shared<SDL_Runner>();
    
    // initialize a text handler
    textHandler_ = std::make_unique<TextHandler>(runner_);
    
    // initialize an audio handler
    audioHandler_ = std::make_unique<AudioHandler>(runner_);
    
    // Create SDL Window
    window_ = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                               screen_width_, screen_height_, SDL_WINDOW_SHOWN);
    if (window_ == nullptr) {
      std::cerr << "Window could not be created." << std::endl;
      std::cerr << "SDL Error: " << SDL_GetError() << std::endl;
    }
    
    // Create SDL Renderer
    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
    if (renderer_ == nullptr) {
      std::cerr << "Renderer could not be created." << std::endl;
      std::cerr << "SDL Error: " << SDL_GetError() << std::endl;
    }
}

Renderer::~Renderer() {
  SDL_DestroyWindow(window_);
  SDL_DestroyRenderer(renderer_);
}

void Renderer::Render(Ball const &ball, std::vector<Player> const &players) {
  // draw the table
  RenderTable();
  
  // draw the ball
  DrawBall(std::move(ball));
  
  // render the players
  for (auto const &player : players) {
    RenderPlayer(player);
  }
  
  // update screen
  SDL_RenderPresent(renderer_);
}

void Renderer::PlayObjectHitSound() const {
  audioHandler_->PlayObjectHitSound();
}

void Renderer::PlayWallHitSound() const {
  audioHandler_->PlayWallHitSound();
}

void Renderer::RenderTable() {
  // Set draw color to black and apply to whole screen
  SDL_SetRenderDrawColor(renderer_, 0x00, 0x00, 0x00, 0xFF);
  SDL_RenderClear(renderer_);
  
  // set draw color to white
  SDL_SetRenderDrawColor(renderer_, 0xFF, 0xFF, 0XFF, 0xFF);
  
  // loop from top to bottom of the screen
  // draw a white point in the center of the screen, skipping every third position
  for (int y = 0; y < screen_height_; ++y) {
    if (y % 3 != 0) {
      SDL_RenderDrawPoint(renderer_, screen_width_ / 2, y);
    }
  }
}
  

void Renderer::DrawBall(Ball ball) {
  SDL_Rect rect{};
  
  rect.x = static_cast<int>(ball.GetPosition().GetX());
  rect.y = static_cast<int>(ball.GetPosition().GetY());
  rect.w = ball.GetWidth();
  rect.h = ball.GetHeight();

  SDL_RenderFillRect(renderer_, &rect);
}

void Renderer::DrawPaddle(Paddle paddle) {
  SDL_Rect rect{};
  
  rect.x = static_cast<int>(paddle.GetPosition().GetX());
  rect.y = static_cast<int>(paddle.GetPosition().GetY());
  rect.w = paddle.GetWidth();
  rect.h = paddle.GetHeight();
  
  SDL_RenderFillRect(renderer_, &rect);
}

void Renderer::RenderPlayer(Player const &player) {
  DrawPaddle(player.GetPaddle());
  textHandler_->DrawPlayerScore(renderer_, player);
}