#include "screenobject.h"
#include "SDL/SDL_opengl.h"
#include "wobblycube.h"

ScreenObject::ScreenObject(int name):
rot_angle_(0.0),
scale_(1.0),
name_(name)
{
  rot_vec_.y(1.0);
}

ScreenObject::~ScreenObject(){
}

void ScreenObject::draw(){
  	glPushMatrix();
		material_.apply();
		glTranslatef(center_.x(),center_.y(),center_.z());
		glRotatef(rot_angle_, rot_vec_.x(), rot_vec_.y(), rot_vec_.z() );
		glScalef(scale_,scale_,scale_);
		if ( name_ >= 0 ){
			glLoadName(name_);
    }
		do_draw();
		draw_selection();
		glPopMatrix();
}

void ScreenObject::set_selected(bool selected){
  if( selected && !selection) {
		selection=ScreenObjectPtr( new WobblyCube() );
  }
  if( !selected && selection ) {
    selection.reset();
  }
}

void ScreenObject::draw_selection(){
  if(selection) {
		glRotatef(-rot_angle_, rot_vec_.x(), rot_vec_.y(), rot_vec_.z() );
		selection->draw();
  }
}

void ScreenObject::animate(){
  if(selection) {
    selection->animate();
  }
  do_animate();
}
