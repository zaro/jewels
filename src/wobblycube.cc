#include "wobblycube.h"
#include "SDL/SDL_opengl.h"
#include <math.h>

WobblyCube::WobblyCube(int name):
ScreenObject(name),
amplitude_(.2),
phase_(0.0),
size_(.3)
{
}

void WobblyCube::do_draw() {
		float s=size_/2.;
		float v[8][3] = {
			{ s, -s, -s},  { s,  s, -s},
			{-s,  s, -s},  {-s, -s, -s},
			{ s, -s,  s},  { s,  s,  s},
			{-s, -s,  s},  {-s,  s,  s}
		};
		int edges[12][2] = {
			{0,1}, {0,3}, {0,4}, {2,1}, {2,3}, {2,7},
			{6,3}, {6,4}, {6,7}, {5,1}, {5,4}, {5,7},
		};
		float a=amplitude_;
    for(int line=0; line< 10 ; line++ ){
			int sp=edges[line][0];
      int ep=edges[line][1];
			int parts=20.0;
			float x1=v[sp][0];
      float y1=v[sp][1];
      float z1=v[sp][2];
			float x2=v[ep][0];
      float y2=v[ep][1];
      float z2=v[ep][2];

			float xs=(x2-x1)/float(parts);
      float ys=(y2-y1)/float(parts);
      float zs=(z2-z1)/float(parts);
			float p = phase_;
			float l=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1));
			float r=0;
			float l_2=l/2.0;
			glBegin(GL_LINE_STRIP);
			glVertex3f(x1,y1,z1);
			parts--;
			while (parts-1){
				x1 = x1 + xs;
				y1 = y1 + ys;
				z1 = z1 + zs;
				r += sqrt(xs*xs + ys*ys +zs*zs);
				if (r>=l_2){
					a=amplitude_ *(l-r);
        }else{
					a=amplitude_ *(r);
        };
				glVertex3f(x1+a*cos(p),y1+a*cos(p),z1+a*cos(p));
				p += 0.09;
				parts--;
      }
			glVertex3f(x2,y2,z2);
			parts--;
			glEnd();
    }
}

void WobblyCube::do_animate() {
  phase_ += 0.2;
}
