#ifndef COLOR_H
#define COLOR_H

class Color {
  float color[4];
public:
  Color() {
    color[0]=1.0;
    color[1]=1.0;
    color[2]=1.0;
    color[3]=1.0;
  }
  Color(float red ,float green,float blue) {
    color[0]=red;
    color[1]=green;
    color[2]=blue;
    color[3]=1.0;
  }
  Color(float red ,float green,float blue,float alpha) {
    color[0]=red;
    color[1]=green;
    color[2]=blue;
    color[3]=alpha;
  }
  Color(const float* colors) {
    for( int i=0 ; i < 4 ; i ++ ){
      color[i]  = colors[i];
    }
  }
  float* as_fv() { return color; }
};

#endif // COLOR_H
