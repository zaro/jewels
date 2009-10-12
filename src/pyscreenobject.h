#ifndef PYSCREENOBJECT_H
#define PYSCREENOBJECT_H

#include "screenobject.h"
#include <boost/python.hpp>

class PyScreenObject : ScreenObject , boost::python::wrapper<ScreenObject> {

public:
  static void register_in_python();
};



#endif //PYSCREENOBJECT_H
