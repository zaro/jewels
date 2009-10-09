#include "animatorfactory.h"
#include <iostream>

#include "pyanimator.h"

#include <boost/bind.hpp>
#include <boost/python.hpp>
#include "python_helper.h"


AnimatorFactory* AnimatorFactory::instance_ = NULL;

AnimatorFactory& AnimatorFactory::instance() {
  if(!instance_){
    instance_  = new AnimatorFactory();
  };
  return *instance_;
}

void AnimatorFactory::register_animator(const std::string& name,AnimatorCreatorFunction animator){
  // Do not add anonymous objects
  if( name.size() == 0 ){
    return;
  };
  AnimatorFactory& af=instance();
  af.map_.insert( AnimatorsMap::value_type( name , animator ) );
}

AnimatorPtr AnimatorFactory::create_animator(const std::string& name,int time_ms){
  AnimatorFactory& af=instance();
  AnimatorsMap::iterator i=af.map_.find( name );
  if( i != af.map_.end() ){
    return AnimatorPtr( (i->second)(time_ms) );
  }
  return AnimatorPtr();
}
void AnimatorFactory::print_animators() {
  AnimatorFactory& af=instance();
  std::cout << "Begin animators list:" << std::endl;

  for(AnimatorsMap::iterator i=af.map_.begin() ; i != af.map_.end() ; ++i ){
    std::cout << i->first << std::endl;
  }

  std::cout << "Animators list end." << std::endl;

}

void AnimatorFactory::py_register_animator(const std::string& name){
  register_animator(name,boost::bind(&AnimatorFactory::create_py_animator,_1,name));
}

AnimatorPtr AnimatorFactory::create_py_animator(int time_ms,const std::string& name){
  return PyAnimator::create(time_ms,name);
  /*
  using namespace boost::python;
  std::cout << "hi from create_py_animator" << std::endl;

  // Retrieve the main module
  //object jewels_module = import("jewels");
  PyObject* jewels_module=PyImport_ImportModule("jewels");

  //object main_module = import("__main__");
  PyObject* main_module=PyImport_ImportModule("__main__");

  // Retrieve the main module's namespace
  //object jewels(jewels_module.attr("__dict__"));
  PyObject* jewels=PyObject_GetAttrString(jewels_module,"__dict__");
  //object global(main_module.attr("__dict__"));
  PyObject* global=PyObject_GetAttrString(main_module,"__dict__");


  // Define the derived class in Python.
  //python::object result = python::exec(
  //  "from embedded_hello import *        \n"
  //  "class PythonDerived(Base):          \n"
  //  "    def hello(self):                \n"
  //  "        return 'Hello from Python!' \n",
  //  global, global);

  //object pyAnimator = jewels[name];
  //object pyAnimator = global[name];
  PyObject* animator_class_name= PyString_FromString(name.c_str());
  PyObject* animator_class = PyObject_GetItem(global,animator_class_name);
  PyObject* py_animator = 0;//PyObject_New(animator_class);

  std::cout << "=================" << std::endl;
  std::cout << "Dump: " << name << std::endl;
  std::cout << "=================" << std::endl;
  PyObject_Print(py_animator, stdout , 0);
  std::cout << std::endl;
  std::cout << "=================" << std::endl;

  // Creating and using instances of the C++ class is as easy as always.
  //CppDerived cpp;
  //BOOST_TEST(cpp.hello() == "Hello from C++!");

  //std::cout << "testing derived class from C++..." << std::endl;

  // But now creating and using instances of the Python class is almost
  // as easy!
  //python::object py_base = PythonDerived();
  //Base& py = python::extract<Base&>(py_base) BOOST_EXTRACT_WORKAROUND;

  //object py_rval = pyAnimator();
  Py_XDECREF(animator_class);
  Py_XDECREF(animator_class_name);
  Py_XDECREF(py_animator);

  Py_XDECREF(jewels_module);
  Py_XDECREF(main_module);
  Py_XDECREF(jewels);
  Py_XDECREF(global);



  return AnimatorPtr();
  */
}

void AnimatorFactory::register_in_python(){
  using namespace boost::python;

  class_<AnimatorFactory,boost::noncopyable>("AnimatorFactory", no_init)
     .def("create_animator", &AnimatorFactory::create_animator)
     .staticmethod("create_animator")
     .def("print_animators", &AnimatorFactory::print_animators)
     .staticmethod("print_animators")
     .def("register_animator",&AnimatorFactory::py_register_animator)
     .staticmethod("register_animator")
  ;
}
