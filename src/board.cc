#include "board.h"
#include "SDL/SDL_opengl.h"

#include "cubicjewel.h"
#include "materialfactory.h"

#include <iostream>

Board::Board(unsigned x_size,unsigned y_size,unsigned z_size):
x_size_(x_size),
y_size_(y_size),
z_size_(z_size)
{
  float d=.5;
  float sx=-d*(float(x_size_)/2.);
  float sy=-d*(float(y_size_)/2.);
  float sz=-d*(float(z_size_)/2.);
  float x_coord=sx;
  board.resize(x_size_ * y_size_ * z_size_);
  for(int x=0; x < x_size_ ; x++){
    float y_coord=sy;
    for(int y=0; y < y_size_ ; y++){
      float z_coord=sz;
      for(int z=0; z < z_size_ ; z++){
        int obj_name = pack_name(x,y,z);
        //std::cout << "Created object named :" << obj_name << std::endl;
        at(x,y,z) = ScreenObjectPtr( new CubicJewel( obj_name ) );
        at(x,y,z)->center() = Point( x_coord , y_coord , z_coord );
        at(x,y,z)->material() =  *MaterialFactory::get_random_material() ;
        z_coord += d;
      }
      y_coord += d;
    }
    x_coord +=d;
  }
}

void Board::do_draw() {
  for(int x=0; x < x_size_ ; x++){
    for(int y=0; y < y_size_ ; y++){
      for(int z=0; z < z_size_ ; z++){
        at(x,y,z)->draw();
      }
    }
  }
}

void Board::do_animate(){
  for(int x=0; x < x_size_ ; x++){
    for(int y=0; y < y_size_ ; y++){
      for(int z=0; z < z_size_ ; z++){
        at(x,y,z)->animate();
      }
    }
  }
}

void Board::object_clicked(int name){
  std::cout << "Object clicked : " << name << std::endl;
  Point p=unpack_name(name);
  int x=p.x();
  int y=p.y();
  int z=p.z();
  if( x >= x_size_ ||  y >= y_size_ || z >= z_size_ ){
    return;
  }
  at(x,y,z)->set_selected(true);
}

