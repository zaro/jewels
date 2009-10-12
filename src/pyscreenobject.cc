#include "pyscreenobject.h"


void PyScreenObject::register_in_python(){
  using namespace boost::python;

  class_<ScreenObject>("ScreenObject")
     .def(init<int>())
     .def("animate",&ScreenObject::animate)
     .def("add_animator",&ScreenObject::add_animator)
  ;

}