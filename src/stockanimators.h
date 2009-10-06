#ifndef STOCKANIMATORS_H
#define STOCKANIMATORS_H

#include "animator.h"

class Animator_XAxeRotator : public Animator {
protected:
  Animator_XAxeRotator(int time_ms=-1): Animator(time_ms) { }
public:
  static AnimatorPtr create(int time_ms=-1){ return AnimatorPtr( new Animator_XAxeRotator(time_ms) ); }
  virtual void init(Point& center,Point& rot_vec,float& rot_angle) {
    rot_vec.x(1.0);
    rot_vec.y(0.0);
    rot_vec.z(0.0);
  }
  virtual void next(Point& center,Point& rot_vec,float& rot_angle) {
    rot_angle ++;
    clock_tick();
  }
};

class Animator_YAxeRotator : public Animator {
protected:
  Animator_YAxeRotator(int time_ms=-1): Animator(time_ms) { }
public:
  static AnimatorPtr create(int time_ms=-1){ return AnimatorPtr( new Animator_YAxeRotator(time_ms) ); }
  virtual void init(Point& center,Point& rot_vec,float& rot_angle) {
    rot_vec.x(0.0);
    rot_vec.y(1.0);
    rot_vec.z(0.0);
  }
  virtual void next(Point& center,Point& rot_vec,float& rot_angle) {
    rot_angle ++;
    clock_tick();
  }
};

#endif // STOCKANIMATORS_H