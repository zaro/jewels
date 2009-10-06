
#include <luabind/luabind.hpp>

#include "animator.h"


int Animator::clock_period_ms_ = 50;

void Animator::set_clock_period_ms( int period_ms) {
  clock_period_ms_=period_ms;
}
int Animator::clock_period_ms() {
	return clock_period_ms_;
}

AnimatorPtr Animator::create(int time_ms) {
  AnimatorPtr rval ( new Animator(time_ms) );
  return rval;
}

std::tr1::shared_ptr<Animator> Animator_create(int time_ms) {
  AnimatorPtr rval ( new Animator(time_ms) );
  return rval;
}



void Animator::register_in_lua(lua_State* L){
  using namespace luabind;

  module(L)
  [
      class_<Animator,AnimatorPtr>("Animator")
      .scope
      [
         def("create", &Animator::create),
         def("set_clock_period_ms", &Animator::set_clock_period_ms),
         def("clock_period_ms", &Animator::clock_period_ms)
      ],
      def("Animator_create", &Animator_create)

  ];
}
