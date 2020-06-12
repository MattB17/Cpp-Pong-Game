#include "text_handler.h"
#include <iostream>

TextHandler::TextHandler(std::shared_ptr<SDL_Runner> runner) : runner_(runner) {
    // intialize SDL_TTF
    if (TTF_Init() == -1) {
      std::cerr << "TTF could not be initialized." << std::endl;
      std::cerr << "TTF Error: " << TTF_GetError() << std::endl;
    }
    
    // load TTF font
    scoreFont_ = TTF_OpenFont("../fonts/DejaVuSansMono.ttf", 32);
    if (scoreFont_ == nullptr) {
      std::cerr << "Font could not be loaded." << std::endl;
      std::cerr << "TTF Error: " << TTF_GetError() << std::endl;
    }
}

TextHandler::~TextHandler() {
  SDL_FreeSurface(surface_);
  SDL_DestroyTexture(texture_);
  TTF_CloseFont(scoreFont_);
  TTF_Quit();
}

void TextHandler::DrawPlayerScore(SDL_Renderer *renderer, Player const &player) {
  // set up a surface and texture for the score in white.
  surface_ = TTF_RenderText_Solid(scoreFont_, 
                                  player.GetScoreString().c_str(), 
                                  {0xFF, 0xFF, 0xFF, 0xFF});
  texture_ = SDL_CreateTextureFromSurface(renderer, surface_);
  
  // get the width and height of the text
  int width, height;
  SDL_QueryTexture(texture_, nullptr, nullptr, &width, &height);
  
  // create a rectangle to display the score
  SDL_Rect rect{};
  rect.x = static_cast<int>(player.GetScoreDisplayPos().GetX());
  rect.y = static_cast<int>(player.GetScoreDisplayPos().GetY());
  rect.w = width;
  rect.h = height;

  // display the text
  SDL_RenderCopy(renderer, texture_, nullptr, &rect);
}