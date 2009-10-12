#include "point.h"
#include <boost/python.hpp>

#include <ostream>
using namespace boost::python;


using namespace boost::python;



template <int n = 0>
struct test_class
{
    explicit test_class(int x) : x(x), magic(7654321 + n) { ++counter; }
    test_class(test_class const& rhs) : x(rhs.x), magic(7654321 + n) { ++counter; }
    virtual ~test_class() { magic = 6666666; x = 9999; --counter; }

    void set(int x) {  this->x = x; }
    int value() const { return x; }
    operator int() const { return x; }
    static int count() { return counter; }

    int x;
    long magic;
    static int counter;

 private:
    void operator=(test_class const&);
};

struct   XX : test_class<>
{
    typedef test_class<> base_t;

      XX(int x) : base_t(x) {}
      XX const operator+(  XX const& r) const { return   XX(value() + r.value()); }

//    typedef int (  XX::*safe_bool)() const;
//    operator safe_bool() const { return value() != 0 ? &  XX::value : 0; }
};


template <int n>
int test_class<n>::counter;

std::ostream& operator<<(std::ostream& s,   XX const& x)
{
    return s << x.value();
}

std::ostream& operator<<(std::ostream& o,Point const& p){
  o << p.to_string() ;
  return o;
}


BOOST_PYTHON_MODULE(operators_ext){
  float (Point::*get_x )() const= &Point::x;
  float (Point::*get_y )() const= &Point::y;
  float (Point::*get_z )() const= &Point::z;
  void  (Point::*set_x )(float) = &Point::x;
  void  (Point::*set_y )(float) = &Point::y;
  void  (Point::*set_z )(float) = &Point::z;

/*
  class_<Point>("Point",init<>())
    .def(init<float,float,float>())
    .def("x",get_x)
    .def("y",get_y)
    .def("z",get_z)
    .def("x",set_x)
    .def("y",set_y)
    .def("z",set_z)
    .def(str(self))
  ;

*/

    class_<  XX>("  XX", init<int>())
        .def("value", &  XX::value)
        .def(str(self))
        ;

}

void Point::register_in_python() {
/*
  using namespace boost::python;

  float (Point::*get_x )() const= &Point::x;
  float (Point::*get_y )() const= &Point::y;
  float (Point::*get_z )() const= &Point::z;
  void  (Point::*set_x )(float) = &Point::x;
  void  (Point::*set_y )(float) = &Point::y;
  void  (Point::*set_z )(float) = &Point::z;


  class_<Point>("Point",init<>())
    .def(init<float,float,float>())
    .def("x",get_x)
    .def("y",get_y)
    .def("z",get_z)
    .def("x",set_x)
    .def("y",set_y)
    .def("z",set_z)
    .def(str(self))
  ;
*/
}