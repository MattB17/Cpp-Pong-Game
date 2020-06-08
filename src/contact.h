#ifndef CONTACT_H
#define CONTACT_H

enum class CollisionType {
  kNone,
  kTop,
  kMiddle,
  kBottom
};

struct Contact {
  CollisionType collisionType;
  float penetration;
};

#endif