#ifndef ANIMATOR_H
#define ANIMATOR_H

#include "point.h"
#include <tr1/memory>

class Animator;

typedef std::tr1::shared_ptr<Animator> AnimatorPtr;


class Animator {

  static int clock_period_ms_;
  int animate_time_ms_;
public:

  static void set_clock_period_ms( int period_ms);
  static int clock_period_ms() ;

protected:
  Animator(int time_ms = -1) : animate_time_ms_(time_ms) { }

public:

  static AnimatorPtr create(int time_ms=-1);
  void clock_tick() {
    if( animate_time_ms_ > clock_period_ms_ ) {
      animate_time_ms_ -= clock_period_ms_;
    } else if( animate_time_ms_ > 0 ) {
      animate_time_ms_=0;
    }
  }
  virtual void init(Point& center,Point& rot_vec,float& rot_angle) {
  }
  virtual void next(Point& center,Point& rot_vec,float& rot_angle) {
    clock_tick();
  }
  virtual bool ended() { return (animate_time_ms_ == 0) ; }
  virtual std::string to_string();

  static void register_in_python();

};


#endif // ANIMATOR_H