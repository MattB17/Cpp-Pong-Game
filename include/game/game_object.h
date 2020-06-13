#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

# include "vec2d.h"

class GameObject {
  public:
    GameObject();
    GameObject(int width, int height);
  
    int GetWidth() const { return width_; }
    int GetHeight() const { return height_; }
    void SetWidth(int width);
    void SetHeight(int height);
  
  private:
    int width_;
    int height_;
};

#endif