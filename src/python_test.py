from jewels import *
from types import *


class BAnimator:
  def init(self,center,rot_vec,rot_angle):
    print "BAnimator center: " ,center.to_string()
    center.x(3.0)
    print "BAnimator center: " ,center.to_string()
  def to_string(self):
    return "BAnimator"
  pass

print dir(AnimatorFactory)
AnimatorFactory.print_animators()

AnimatorFactory.register_animator("BAnimator")

AnimatorFactory.print_animators()

a=AnimatorFactory.create_animator('xaxe_rotator',-1)

print dir(a)
print type(a)
print a.to_string()
print  "---------------"
b=AnimatorFactory.create_animator('BAnimator',-1)
print dir(b)
print type(b)
print b.to_string()

#c,r,ra=Point(),Point(),0.3
so=ScreenObject()
#b.init(c,r,ra)
so.add_animator(b)
