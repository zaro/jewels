#include "camera.h"
#include "SDL/SDL_opengl.h"

void Camera::apply() {
		gluLookAt(
							eye_.x(), eye_.y(), eye_.z() ,
							ref_.x(), ref_.y(),	ref_.z() ,
							0, 1, 0
							);
}
