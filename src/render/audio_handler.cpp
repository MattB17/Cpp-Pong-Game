#include "audio_handler.h"
#include <iostream>

AudioHandler::AudioHandler(std::shared_ptr<SDL_Runner> runner) : runner_(runner) {
  // initialize audio  
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
    std::cerr << "Audio could not be opened." << std::endl;
    std::cerr << "Mixer Error: " << Mix_GetError() << std::endl;
  }
  
  // load wall hit sound
  wallHitSound_ = Mix_LoadWAV("../sounds/WallHit.wav");
  if (wallHitSound_ == nullptr) {
    std::cerr << "Wall audio could not be loaded." << std::endl;
    std::cerr << "Mixer Error: " << Mix_GetError() << std::endl;
  }
  
  // load object hit sound
  objectHitSound_ = Mix_LoadWAV("../sounds/ObjectHit.wav");
  if (objectHitSound_ == nullptr) {
    std::cerr << "Object audio could not be loaded." << std::endl;
    std::cerr << "Mixer Error: " << Mix_GetError() << std::endl;
  }
}

AudioHandler::~AudioHandler() {
  Mix_FreeChunk(wallHitSound_);
  Mix_FreeChunk(objectHitSound_);
  Mix_Quit();
}

void AudioHandler::PlayObjectHitSound() const {
  Mix_PlayChannel(-1, objectHitSound_, 0);
}

void AudioHandler::PlayWallHitSound() const {
  Mix_PlayChannel(-1, wallHitSound_, 0);
}