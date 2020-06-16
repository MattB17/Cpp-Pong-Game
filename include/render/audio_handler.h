#ifndef AUDIO_HANDLER_H
#define AUDIO_HADNLER_H

#include "SDL_runner.h"
#include <memory>

class AudioHandler {
  public:
    AudioHandler(std::shared_ptr<SDL_Runner> runner);
    ~AudioHandler();
  
    // no copying or moving audio handlers
    AudioHandler(const AudioHandler& source) = delete;
    AudioHandler& operator=(const AudioHandler& source) = delete;
    AudioHandler(AudioHandler&& source) = delete;
    AudioHandler& operator=(AudioHandler&& source) = delete;
  
    void PlayObjectHitSound() const;
    void PlayWallHitSound() const;
  
  private:
    std::shared_ptr<SDL_Runner> runner_;
  
    Mix_Chunk *wallHitSound_;
    Mix_Chunk *objectHitSound_;
};

#endif