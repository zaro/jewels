#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <sstream>

enum Axis { X = 0, Y = 1 , Z = 2 , W=3 };

class Point {
  float axis[4];
public:
  Point() {
    axis[X]=axis[Y]=axis[Z]=0.0;
    axis[W]=1.0;
  }
  Point(float x,float y,float z) {
    axis[X]=x;
    axis[Y]=y;
    axis[Z]=z;
    axis[W]=1.0 ;
  }
  float x() {
    return axis[X];
  }
  float y() {
    return axis[Y];
  }
  float z() {
    return axis[Z];
  }
  void x(float x) {
    axis[X]=x;
  }
  void y(float y) {
    axis[Y]=y;
  }
  void z(float z) {
    axis[Z]=z;
  }
  float * as_fv() {
    return axis;
  }

  std::string to_string() {
    std::ostringstream o;
    o << "Point[x(" << x() << "),y(" << y() << "),z(" << z() << ")]";
    return o.str();
  }

  static void register_in_python();
};


#endif //POINT_H
