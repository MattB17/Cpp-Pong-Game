#ifndef VEC2D_H
#define VEC2D_H

class Vec2D {
  public:
    Vec2D() : x_(0.0f), y_(0.0f) {}
    Vec2D(float x, float y);
    
    float getX() const { return x_; }
    void setX(float x);
    float getY() const { return y_; }
    void setY(float y);
  
    Vec2D operator+(Vec2D const &other);
    Vec2D& operator+=(Vec2D const &other);
    Vec2D operator*(float scalar);
  
  private:
    float x_;
    float y_;
};

#endif