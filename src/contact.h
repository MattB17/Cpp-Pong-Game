#ifndef CONTACT_H
#define CONTACT_H

enum class CollisionType {
  kNone,
  kTop,
  kMiddle,
  kBottom,
  kLeft,
  kRight
};

struct Contact {
  CollisionType collisionType;
  float penetration;
};

#endif