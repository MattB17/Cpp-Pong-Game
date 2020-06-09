#include "renderer.h"
#include "constants.h"
#include <iostream>
#include <string>
#include <stdlib.h>

Renderer::Renderer()
  : screen_width_(kScreenWidth), screen_height_(kScreenHeight) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
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
    scoreFont_ = TTF_OpenFont("../fonts/DejaVuSansMono.ttf", 32);
    if (scoreFont_ == nullptr) {
      std::cerr << "Font could not be loaded." << std::endl;
      std::cerr << "TTF Error: " << TTF_GetError() << std::endl;
    }
    
    Mix_AllocateChannels(1);
    
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
      std::cerr << "Audio could not be opened." << std::endl;
      std::cerr << "Mixer Error: " << Mix_GetError() << std::endl;
    }
    
    wallHitSound_ = Mix_LoadWAV("../sounds/WallHit.wav");
    if (wallHitSound_ == nullptr) {
      std::cerr << "Wall audio could not be loaded." << std::endl;
      std::cerr << "Mixer Error: " << Mix_GetError() << std::endl;
    }
   
    objectHitSound_ = Mix_LoadWAV("../sounds/PaddleHit.wav");
    if (objectHitSound_ == nullptr) {
      std::cerr << "Object audio could not be loaded." << std::endl;
      std::cerr << "Mixer Error: " << Mix_GetError() << std::endl;
    }
}

Renderer::~Renderer() {
  SDL_DestroyWindow(window_);
  SDL_FreeSurface(surface_);
  SDL_DestroyTexture(texture_);
  TTF_CloseFont(scoreFont_);
  Mix_FreeChunk(wallHitSound_);
  Mix_FreeChunk(objectHitSound_);
  TTF_Quit();
  SDL_Quit();
  Mix_Quit();
}

void Renderer::Render(Ball ball, std::vector<Player> const &players) {
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
  DrawBall(std::move(ball));
  
  // render the players
  for (auto player : players) {
    RenderPlayer(player);
  }
  
  // update screen
  SDL_RenderPresent(renderer_);
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

void Renderer::RenderPlayer(Player &player) {
  DrawPaddle(player.GetPaddle());
  
  surface_ = TTF_RenderText_Solid(scoreFont_, 
                                  player.GetScoreString().c_str(), 
                                  {0xFF, 0xFF, 0xFF, 0xFF});
  texture_ = SDL_CreateTextureFromSurface(renderer_, surface_);
  
  int width, height;
  SDL_QueryTexture(texture_, nullptr, nullptr, &width, &height);
  
  SDL_Rect rect{};
  
  rect.x = static_cast<int>(player.GetScoreDisplayPos().GetX());
  rect.y = static_cast<int>(player.GetScoreDisplayPos().GetY());
  rect.w = width;
  rect.h = height;
  
  SDL_RenderCopy(renderer_, texture_, nullptr, &rect);
}