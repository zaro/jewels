#include "pyanimator.h"

#include <iostream>

AnimatorPtr PyAnimator::create(int time_ms,const std::string& python_class_name) {
  PyAnimator* pyanim=NULL;
  boost::python::object main_module = boost::python::import("__main__");
  boost::python::object global(main_module.attr("__dict__"));
  boost::python::object py_animator_class = global[python_class_name];
  if( py_animator_class ) {
    boost::python::object python_object = py_animator_class();
    if( python_object ) {
      pyanim=new PyAnimator(time_ms,python_class_name);
      pyanim->python_object_ = python_object;
    }
  }
  return AnimatorPtr(pyanim);
}

void PyAnimator::init(Point& center,Point& rot_vec,float& rot_angle) {
  //boost::python::call_method<void>(python_object_.ptr(), "init",boost::ref(center),boost::ref(rot_vec),boost::ref(rot_angle)  );
  std::cout << "PyAnimator center:" <<center.to_string() << std::endl;
  boost::python::call_method<void>(python_object_.ptr(), "init" , boost::ref(center),boost::ref(rot_vec),rot_angle );
  std::cout << "PyAnimator center:"<< center.to_string() << std::endl;
}

void PyAnimator::next(Point& center,Point& rot_vec,float& rot_angle) {
  //boost::python::call_method<void>(python_object_.ptr(), "ended",boost::ref(center),boost::ref(rot_vec),boost::ref(rot_angle) );
  clock_tick();
}

bool PyAnimator::ended() {
  //return boost::python::call_method<bool>(python_object_.ptr(), "ended");
}

std::string PyAnimator::to_string(){
  std::cout << "hi from pyanimator" << std::endl;
  return python_class_name_;
}