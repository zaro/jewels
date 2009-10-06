#ifndef LIGHT_H
#define LIGHT_H

#include "point.h"

class Light {
  Point pos_;
  int number_;
public:
  Light();
  void setup();
  void apply();
  Point& pos() { return pos_; }
};


#endif // LIGHT_H
