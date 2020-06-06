#include "renderer.h"
#include "constants.h"
#include <iostream>
#include <string>
#include <stdlib.h>

Renderer::Renderer()
  : screen_width_(kScreenWidth), screen_height_(kScreenHeight) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
      std::cerr << "SDL could not initialize." << std::endl;
      std::cerr << "SDL Error: " << SDL_GetError() << std::endl;
    }
    
    if (TTF_Init() == -1) {
      std::cerr << "TTF could not be initialized." << std::endl;
      std::cerr << "TTF Error: " << TTF_GetError() << std::endl;
    }
    
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
      
   // load TTF font
   scoreFont_ = TTF_OpenFont("../fonts/DejaVuSansMono.ttf", 40);
   if (scoreFont_ == nullptr) {
     std::cerr << "Font could not be loaded." << std::endl;
     std::cerr << "TTF Error: " << TTF_GetError() << std::endl;
   }
}

Renderer::~Renderer() {
  SDL_DestroyWindow(window_);
  TTF_CloseFont(scoreFont_);
  TTF_Quit();
  SDL_Quit();
}

void Renderer::Render(Ball ball, std::vector<Paddle> paddles) {
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
  
  // draw the ball
  drawBall(std::move(ball));
  
  // draw the paddles
  for (auto paddle : paddles) {
    drawPaddle(std::move(paddle));
  }
  
  // update screen
  SDL_RenderPresent(renderer_);
}

void Renderer::drawBall(Ball ball) {
  SDL_Rect rect{};
  
  rect.x = static_cast<int>(ball.getPosition().getX());
  rect.y = static_cast<int>(ball.getPosition().getY());
  rect.w = ball.getWidth();
  rect.h = ball.getHeight();

  SDL_RenderFillRect(renderer_, &rect);
}

void Renderer::drawPaddle(Paddle paddle) {
  SDL_Rect rect{};
  
  rect.x = static_cast<int>(paddle.getPosition().getX());
  rect.y = static_cast<int>(paddle.getPosition().getY());
  rect.w = paddle.getWidth();
  rect.h = paddle.getHeight();
  
  SDL_RenderFillRect(renderer_, &rect);
}