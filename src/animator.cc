#include "animator.h"
#include <string>

#include <boost/python.hpp>

#include "python_helper.h"


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

std::string Animator::to_string(){
  return "Animator";
}



struct AnimatorWrap : Animator, boost::python::wrapper<Animator>
{
    std::string to_string()
    {
        if (boost::python::override f = this->get_override("to_string"))
            return f(); // *note*
        return Animator::to_string();
    }
    std::string default_to_string() { return this->Animator::to_string(); }
};



void Animator::register_in_python(){
  using namespace boost::python;

  class_<Animator,AnimatorPtr,boost::noncopyable>("Animator", no_init)
     .def("create", &Animator::create)
     .staticmethod("create")
     .def("set_clock_period_ms", &Animator::set_clock_period_ms)
     .staticmethod("set_clock_period_ms")
     .def("clock_period_ms", &Animator::clock_period_ms)
     .staticmethod("clock_period_ms")
     .def("to_string",&Animator::to_string ,&AnimatorWrap::to_string )
  ;
}
