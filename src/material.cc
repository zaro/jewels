#include "material.h"
#include "materialfactory.h"
#include "SDL/SDL_opengl.h"

Material::Material(){
};

Material::Material(const std::string& name,const Color& ambient,const Color& diffuse,const Color& specular,float shininess):
name_(name),
ambient_(ambient),
diffuse_(diffuse),
specular_(specular),
shininess_(shininess)
{
  MaterialFactory::add_material( this );
};

Material::~Material(){
  MaterialFactory::remove_material( this );
};

void Material::apply() {
  glMaterialfv(GL_FRONT,GL_AMBIENT,ambient_.as_fv());
  glMaterialfv(GL_FRONT,GL_DIFFUSE,diffuse_.as_fv());
  glMaterialfv(GL_FRONT,GL_SPECULAR,specular_.as_fv());
  glMaterialfv(GL_FRONT,GL_SHININESS,&shininess_);
}