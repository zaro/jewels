#include <stdio.h>

#include "point.h"
#include "animator.h"
#include "animatorfactory.h"
#include "stockanimators.h"

#include <Python.h>
#include <boost/python.hpp>

BOOST_PYTHON_MODULE(jewels) {
  Point::register_in_python();
  Animator::register_in_python();
  AnimatorFactory::register_in_python();
}

int
main(int argc, char *argv[])
{
  if (argc<2) {
    printf("%s: <filename.python>\n",argv[0]);
    return 0;
  }

  AnimatorFactory::register_animator("yaxe_rotator",Animator_YAxeRotator::create);
  AnimatorFactory::register_animator("xaxe_rotator",Animator_XAxeRotator::create);


  Py_Initialize();

  initjewels();

  PyRun_SimpleString("from time import time,ctime\n"
                     "print 'Today is',ctime(time())\n");
  FILE *f=fopen(argv[1],"r");
  if(f) {
    PyRun_SimpleFile(f,argv[1]);
    fclose(f);
  }else{
    printf("unable to open %s\n",argv[1]);
  }

  Py_Finalize();
  return 0;
}
