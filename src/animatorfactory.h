#ifndef ANIMATORFACTORY_H
#define ANIMATORFACTORY_H

#include <string>
#include <map>

#include "animator.h"

#include <boost/function.hpp>

typedef AnimatorPtr (*AnimatorCreator)(int) ;

class AnimatorFactory {
  friend class Animator;

private:
  typedef boost::function<AnimatorPtr (int)> AnimatorCreatorFunction;
  typedef std::map< std::string ,AnimatorCreatorFunction > AnimatorsMap;
  AnimatorsMap map_;

  static AnimatorFactory* instance_;
  static AnimatorFactory& instance();

  static AnimatorPtr create_py_animator(int time_ms,const std::string& name);

public:
  static void register_animator(const std::string& name,AnimatorCreatorFunction animator);
  static void py_register_animator(const std::string& name);

  static AnimatorPtr create_animator(const std::string& name,int time_ms=-1);
  static void print_animators();

  static void register_in_python();
};


#endif // ANIMATORFACTORY_H