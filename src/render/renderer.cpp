#include "renderer.h"
#include "constants.h"
#include <iostream>
#include <future>
#include <thread>
#include <string>
#include <stdlib.h>

Renderer::Renderer() 
  : center_(Vec2D(kScreenWidth / 2.0f, kScreenHeight / 2.0f)) {
    // Run SDL
    runner_ = std::make_shared<SDL_Runner>();
    
    // initialize a text handler
    textHandler_ = std::make_unique<TextHandler>(runner_);
    
    // initialize an audio handler
    audioHandler_ = std::make_unique<AudioHandler>(runner_);
    
    // initialize SDL_window
    window_ = SDL_CreateWindow("Pong", 
                               SDL_WINDOWPOS_CENTERED, 
                               SDL_WINDOWPOS_CENTERED,
                               center_.GetX() * 2.0f, 
                               center_.GetY() * 2.0f, 
                               SDL_WINDOW_SHOWN);
    if (window_ == nullptr) {
      std::cerr << "Window could not be created." << std::endl;
      std::cerr << "SDL Error: " << SDL_GetError() << std::endl;
    }
    
    // initialize renderer
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

void Renderer::Render(Ball const &ball, Player const &user, Player const &computerAI) {
  // draw the table
  RenderGameBoard(user, computerAI);
  
  // draw the ball
  DrawBall(std::move(ball));
  
  // update screen
  SDL_RenderPresent(renderer_);
}

void Renderer::RenderCountPage(int count, Player const &user, Player const &computerAI) {
  // draw the table
  RenderGameBoard(user, computerAI);
  
  // draw count in center of screen
  textHandler_->DrawCount(renderer_, count, center_);
  
  // update screen
  SDL_RenderPresent(renderer_);
}

void Renderer::PlayObjectHitSound() const {
  audioHandler_->PlayObjectHitSound();
}

void Renderer::PlayWallHitSound() const {
  audioHandler_->PlayWallHitSound();
}

void Renderer::RenderGameBoard(Player const &user, Player const &computerAI) {
  // draw the table
  RenderTable();
  
  // render the players
  RenderPlayer(user);
  RenderPlayer(computerAI);
}

void Renderer::RenderTable() {
  // Set draw color to black and apply to whole screen
  SDL_SetRenderDrawColor(renderer_, 0x00, 0x00, 0x00, 0xFF);
  SDL_RenderClear(renderer_);
  
  // set draw color to white
  SDL_SetRenderDrawColor(renderer_, 0xFF, 0xFF, 0XFF, 0xFF);
  
  // loop from top to bottom of the screen
  // draw a white point in the center of the screen, skipping every third position
  for (int y = 0; y < (center_.GetY() * 2.0f); ++y) {
    if (y % 3 != 0) {
      SDL_RenderDrawPoint(renderer_, center_.GetX(), y);
    }
  }
}
  

void Renderer::DrawBall(Ball const &ball) {
  SDL_Rect rect{};
  
  rect.x = static_cast<int>(ball.GetPosition().GetX());
  rect.y = static_cast<int>(ball.GetPosition().GetY());
  rect.w = ball.GetWidth();
  rect.h = ball.GetHeight();

  SDL_RenderFillRect(renderer_, &rect);
}

void Renderer::DrawPaddle(Paddle const &paddle) {
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