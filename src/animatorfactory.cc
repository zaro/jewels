#include "animatorfactory.h"
#include <iostream>

AnimatorFactory* AnimatorFactory::instance_ = NULL;

AnimatorFactory& AnimatorFactory::instance() {
  if(!instance_){
    instance_  = new AnimatorFactory();
  };
  return *instance_;
}

void AnimatorFactory::register_animator(const std::string& name,AnimatorCreator animator){
  // Do not add anonymous objects
  if( name.size() == 0 ){
    return;
  };
  AnimatorFactory& af=instance();
  af.map_.insert( AnimatorsMap::value_type( name , animator ) );
}

AnimatorPtr AnimatorFactory::create_animator(const std::string& name,int time_ms){
  AnimatorFactory& af=instance();
  AnimatorsMap::iterator i=af.map_.find( name );
  if( i != af.map_.end() ){
    return AnimatorPtr( (i->second)(time_ms) );
  }
  return AnimatorPtr();
}
void AnimatorFactory::print_animators() {
  AnimatorFactory& af=instance();
  std::cout << "Begin animators list:" << std::endl;

  for(AnimatorsMap::iterator i=af.map_.begin() ; i != af.map_.end() ; ++i ){
    std::cout << i->first << std::endl;
  }

  std::cout << "Animators list end." << std::endl;

}