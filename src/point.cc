#include "point.h"
#include <boost/python.hpp>

void Point::register_in_python() {
  using namespace boost::python;

  float (Point::*get_x)() = &Point::x;
  float (Point::*get_y)() = &Point::y;
  float (Point::*get_z)() = &Point::z;
  void  (Point::*set_x)(float) = &Point::x;
  void  (Point::*set_y)(float) = &Point::y;
  void  (Point::*set_z)(float) = &Point::z;


  class_<Point>("Point")
    .def(init<>())
    .def(init<float,float,float>())
    .def("x",get_x)
    .def("y",get_y)
    .def("z",get_z)
    .def("x",set_x)
    .def("y",set_y)
    .def("z",set_z)
  ;

}