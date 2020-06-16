#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "vec2d.h"
#include <memory> 

class GameObject {
  public:
    GameObject();
    GameObject(int width, int height);
  
    int GetWidth() const { return width_; }
    int GetHeight() const { return height_; }
    void SetWidth(int width);
    void SetHeight(int height);
  
    const Vec2D &GetPosition() const { return *pos_; }
    const Vec2D GetVelocity() const { return *velocity_; }
    void UpdatePosition(float elapsedTime);
  
  protected:
    std::unique_ptr<Vec2D> pos_;
    std::unique_ptr<Vec2D> velocity_;
  
  private:
    int width_;
    int height_;
};

#endif