#ifndef CUBICJEWEL_H
#define CUBICJEWEL_H

#include "screenobject.h"

class CubicJewel: public ScreenObject {
  float size_;
public:
  CubicJewel(int name=-1);
  void do_draw();
  void do_animate();
};

#endif //CUBICJEWEL_H
