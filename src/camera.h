#ifndef CAMERA_H
#define CAMERA_h

#include "point.h"

class Camera {
  Point eye_;
  Point ref_;
public:
  void apply();
  Point& eye() { return eye_; }
  Point& ref() { return ref_; } 
};

#endif //CAMERA_H
