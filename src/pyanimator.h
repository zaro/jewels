#ifndef PYANIMATOR_H
#define PYANIMATOR_H

#include "animator.h"
#include <tr1/memory>

#include <boost/python.hpp>

class PyAnimator : public Animator{
  std::string python_class_name_;
  boost::python::object python_object_;
protected:
  PyAnimator(int time_ms,const std::string& python_class_name) :
    Animator(time_ms) ,
    python_class_name_(python_class_name)  {
    }

public:
  static AnimatorPtr create(int time_ms,const std::string& python_class_name);
  virtual void init(Point& center,Point& rot_vec,float& rot_angle);
  virtual void next(Point& center,Point& rot_vec,float& rot_angle);
  virtual bool ended();
  virtual std::string to_string();

};


#endif // PYANIMATOR_H