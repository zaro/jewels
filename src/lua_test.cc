#include <stdio.h>

#include "lua.hpp"

#include "animator.h"
#include "animatorfactory.h"
#include "stockanimators.h"


int main(int argc,char* argv[])
{
 lua_State *L;
 if (argc<2)
 {
  printf("%s: <filename.lua>\n",argv[0]);
  return 0;
 }

 AnimatorFactory::register_animator("yaxe_rotator",Animator_YAxeRotator::create);
 AnimatorFactory::register_animator("xaxe_rotator",Animator_XAxeRotator::create);

 L=lua_open();
 luaopen_base(L);	// load basic libs (eg. print)
 luaopen_table(L);
 //luaopen_io(L);
 luaopen_string(L);
 //luaopen_math(L);

 Animator::register_in_lua(L);

 if (luaL_loadfile(L,argv[1])==0){ // load and run the file
  if( lua_pcall(L,0,0,0) ) {
    fprintf(stderr, "lua couldn't execute '%s': %s.\n",argv[1], lua_tostring(L, -1));
    lua_pop(L, 1);
  }
 }else{
  printf("unable to load %s\nerror: %s\n",argv[1] , lua_tostring(L, -1) );
 }
 lua_close(L);
 return 0;
}
