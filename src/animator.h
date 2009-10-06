#ifndef ANIMATOR_H
#define ANIMATOR_H

#include "point.h"
#include <tr1/memory>

#include "luahelper.h"

class Animator;

typedef std::tr1::shared_ptr<Animator> AnimatorPtr;


class Animator {

  static int clock_period_ms_;
  int animate_time_ms_;
public:

  static void set_clock_period_ms( int period_ms);
  static int clock_period_ms() ;

protected:
  friend std::tr1::shared_ptr<Animator> Animator_create(int time_ms);;
  Animator(int time_ms = -1) : animate_time_ms_(time_ms) { }

public:

  static AnimatorPtr create(int time_ms);
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

  static void register_in_lua(lua_State* L);

};


#endif // ANIMATOR_H