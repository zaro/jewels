from jewels import *
from types import *

print type(Animator)

class BAnimator(Animator):
  def to_string(self):
    return "BAnimator"
  pass

print dir(Animator)

print dir(AnimatorFactory)
AnimatorFactory.print_animators()

AnimatorFactory.register_animator("BAnimator")

AnimatorFactory.print_animators()

a=AnimatorFactory.create_animator('xaxe_rotator',-1)

print dir(a)
print type(a)
print a.to_string()

b=AnimatorFactory.create_animator('BAnimator',-1)
print dir(b)
print type(b)
print b.to_string()

