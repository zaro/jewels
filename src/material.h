#ifndef MATERIAL_H
#define MATERIAL_H

#include "color.h"
#include <string>


class Material {
  Color ambient_;
  Color diffuse_;
  Color specular_;
  float shininess_;
  std::string name_;
public:
  Material();
  Material(const std::string& name,const Color& ambient,const Color& diffuse,const Color& specular,float shininess);
  ~Material();
  void apply();
  const std::string& name() { return name_; }
};


#endif// MATERIAL_H
