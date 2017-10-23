#ifndef SCREENOBJECT_H
#define SCREENOBJECT_H


#include "material.h"
#include "point.h"
#include <memory>

class ScreenObject ;

typedef std::shared_ptr<ScreenObject> ScreenObjectPtr;

class ScreenObject {
protected:
  Point center_;
  float rot_angle_;
  Point rot_vec_;
  Material material_;
  float scale_;
  int name_;
  ScreenObjectPtr selection;
public:
  ScreenObject(int name=-1);
  ~ScreenObject();
  void draw();
  void animate();
	virtual void do_draw() =0;
	virtual void do_animate() =0;
	virtual void set_selected(bool selected);
	void draw_selection();
  Point& center() {  return center_; }
  Material& material() { return material_; }
};


#endif // SCREENOBJECT_H
