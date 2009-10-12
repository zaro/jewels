#ifndef SCREENOBJECT_H
#define SCREENOBJECT_H


#include "material.h"
#include "point.h"
#include "animator.h"
#include <tr1/memory>
#include <list>

class ScreenObject ;

typedef std::tr1::shared_ptr<ScreenObject> ScreenObjectPtr;

class ScreenObject {
protected:
  Point center_;
  float rot_angle_;
  Point rot_vec_;
  Material material_;
  float scale_;
  int name_;
  ScreenObjectPtr selection;
  typedef std::list<AnimatorPtr> AnimatorList;
  AnimatorList animators_;
public:
  ScreenObject(int name=-1);
  ~ScreenObject();
  void draw();
  void animate();
	virtual void do_draw();
	virtual void do_animate();
	virtual void set_selected(bool selected);
  virtual void add_animator(AnimatorPtr animator);
	void draw_selection();
  Point& center() {  return center_; }
  Material& material() { return material_; }

};


#endif // SCREENOBJECT_H

