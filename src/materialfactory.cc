#include "materialfactory.h"
#include "material.h"
#include <iostream>
#include <stdlib.h>


MaterialFactory* MaterialFactory::instance_ = NULL;

MaterialFactory& MaterialFactory::instance() {
  if(!instance_){
    instance_  = new MaterialFactory();
  };
  return *instance_;
}

void MaterialFactory::add_material(Material *material){
  // Do not add anonymous objects
  if( material->name().size() == 0 ){
    return;
  };
  MaterialFactory& me=instance();
  me.map_.insert( MaterialMap::value_type( material->name() , material ) );
}

void MaterialFactory::remove_material(Material *material){
  // Anonymous object don't need removal
  if( material->name().size() == 0 ){
    return;
  };
  MaterialFactory& me=instance();
  MaterialMap::iterator i=me.map_.find( material->name() );
  if( i != me.map_.end() ) {
    me.map_.erase( i );
  }
}

Material*  MaterialFactory::get_material(const std::string& name) {
  MaterialFactory& me=instance();
  MaterialMap::const_iterator i=me.map_.find( name );
  return i->second;
};

Material* MaterialFactory::get_random_material(){
  MaterialFactory& me=instance();
  int n=rand() % me.map_.size();
  MaterialMap::const_iterator i=me.map_.begin();
  while(n>0){
    i++;
    n--;
  }
  return i->second;
}


void MaterialFactory::print_materials() {
  MaterialFactory& me=instance();
  for( MaterialMap::const_iterator i=me.map_.begin(); i != me.map_.end() ; ++i ){
    std::cout << i->second->name() << std::endl ;
  };
}

#include "materials.h"
