#ifndef WOBBLYCUBE_H
#define WOBBLYCUBE_H

#include "screenobject.h"

class WobblyCube : public ScreenObject {
  float amplitude_;
  float phase_;
  float size_;
public:
  WobblyCube(int name=-1);
  void do_draw();
  void do_animate();
  void set_phase(float phase) {  phase_ = phase; };
  void set_amplitude(float amplitude) {  amplitude_ = amplitude; };
};

#endif //WOBBLYCUBE_H
