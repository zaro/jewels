#ifndef ANIMATORFACTORY_H
#define ANIMATORFACTORY_H

#include <string>
#include <map>

#include "animator.h"

typedef AnimatorPtr (*AnimatorCreator)(int) ;

class AnimatorFactory {
  friend class Animator;

private:
  typedef std::map< std::string , AnimatorCreator > AnimatorsMap;
  AnimatorsMap map_;

  static AnimatorFactory* instance_;
  static AnimatorFactory& instance();

public:
  static void register_animator(const std::string& name,AnimatorCreator animator);

  static AnimatorPtr create_animator(const std::string& name,int time_ms=-1);
  static void print_animators();

};


#endif // ANIMATORFACTORY_H