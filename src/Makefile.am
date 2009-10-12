AUTOMAKE_OPTIONS = gnu

AM_CPPFLAGS = $(SDL_CFLAGS) `python-config --cflags`
AM_LDFLAGS = $(SDL_LIBS) `python-config --libs` -lboost_python-mt-py26

bin_PROGRAMS = jewels python_test
jewels_SOURCES = jewels.cc game.cc screenobject.cc material.cc materialfactory.cc camera.cc cubicjewel.cc wobblycube.cc light.cc board.cc animator.cc animatorfactory.cc  pyanimator.cc

python_test_SOURCES = python_test.cc animator.cc animatorfactory.cc pyanimator.cc point.cc screenobject.cc pyscreenobject.cc material.cc wobblycube.cc materialfactory.cc