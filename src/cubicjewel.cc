#include "cubicjewel.h"
#include "SDL/SDL_opengl.h"

#include "animatorfactory.h"

CubicJewel::CubicJewel(int name):
ScreenObject(name),
size_(.3)
{
  add_animator( AnimatorFactory::create_animator("xaxe_rotator") );
}


void CubicJewel::do_draw(){
	glBegin(GL_QUADS);

	float s=size_/2;
	glNormal3f(0.0,0.0,-1.0);
	glVertex3f(-s,-s,-s);
	glNormal3f(0.0,0.0,-1.0);
	glVertex3f(+s,-s,-s);
	glNormal3f(0.0,0.0,-1.0);
	glVertex3f(+s,+s,-s);
	glNormal3f(0.0,0.0,-1.0);
	glVertex3f(-s,+s,-s);

	glNormal3f(0.0,1.0,0.0);
	glVertex3f(+s,+s,-s);
	glNormal3f(0.0,1.0,0.0);
	glVertex3f(-s,+s,-s);
	glNormal3f(0.0,1.0,0.0);
	glVertex3f(-s,+s,+s);
	glNormal3f(0.0,1.0,0.0);
	glVertex3f(+s,+s,+s);

	glNormal3f(0.0,0.0,1.0);
	glVertex3f(-s,+s,+s);
	glNormal3f(0.0,0.0,1.0);
	glVertex3f(+s,+s,+s);
	glNormal3f(0.0,0.0,1.0);
	glVertex3f(+s,-s,+s);
	glNormal3f(0.0,0.0,1.0);
	glVertex3f(-s,-s,+s);

	glNormal3f(0.0,-1.0,0.0);
	glVertex3f(+s,-s,+s);
	glNormal3f(0.0,0.0,-1.0);
	glVertex3f(-s,-s,+s);
	glNormal3f(0.0,0.0,-1.0);
	glVertex3f(-s,-s,-s);
	glNormal3f(0.0,0.0,-1.0);
	glVertex3f(+s,-s,-s);

	glNormal3f(1.0,0.0,0.0);
	glVertex3f(+s,+s,+s);
	glNormal3f(1.0,0.0,0.0);
	glVertex3f(+s,+s,-s);
	glNormal3f(1.0,0.0,0.0);
	glVertex3f(+s,-s,-s);
	glNormal3f(1.0,0.0,0.0);
	glVertex3f(+s,-s,+s);

	glNormal3f(-1.0,0.0,0.0);
	glVertex3f(-s,+s,+s);
	glNormal3f(-1.0,0.0,0.0);
	glVertex3f(-s,+s,-s);
	glNormal3f(-1.0,0.0,0.0);
	glVertex3f(-s,-s,-s);
	glNormal3f(-1.0,0.0,0.0);
	glVertex3f(-s,-s,+s);
	glEnd();
}


