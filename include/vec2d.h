#ifndef VEC2D_H
#define VEC2D_H

class Vec2D {
  public:
    Vec2D() : x_(0.0f), y_(0.0f) {}
    Vec2D(float x, float y) : x_(x), y_(y) {}
    
    float GetX() const { return x_; }
    void SetX(float x) { x_ = x; }
    float GetY() const { return y_; }
    void SetY(float y) { y_ = y; }
  
    bool operator==(const Vec2D& other);
    bool operator!=(const Vec2D& other);
    Vec2D operator+(const Vec2D& other);
    Vec2D& operator+=(const Vec2D& other);
    Vec2D operator*(float scalar);
  
  private:
    float x_;
    float y_;
};

#endif