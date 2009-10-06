#include "light.h"
#include "SDL/SDL_opengl.h"

Light::Light() :
number_(GL_LIGHT0)
{
}

void Light::setup() {
  float ambient[] = {0.2, 0.2, 0.2, 1.0};
  float diffuse[] = {1.0, 1.0, 1.0, 1.0};
  float specular[] = {1.0, 1.0, 1.0, 1.0};
  float lm[] = {0.2, 0.2, 0.2, 1.0};
  glLightfv(number_, GL_AMBIENT, ambient);
	glLightfv(number_, GL_DIFFUSE, diffuse);
	glLightfv(number_, GL_SPECULAR, specular);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lm);
	glEnable(number_);
}

void Light::apply() {
		glLightfv(number_, GL_POSITION, pos_.as_fv() );
}
