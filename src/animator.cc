#include "animator.h"

#include <luabind/luabind.hpp>

int Animator::clock_period_ms_ = 50;

AnimatorPtr Animator::create(int time_ms) {
  AnimatorPtr rval ( new Animator(time_ms) );
  return rval;
}

void Animator::register_in_lua(lua_State* L){
  using namespace luabind;

  module(L)
  [
      class_<Animator>("Animator")
        .scope
        [
          def("create", &Animator::create)
        ]
  ];
}
