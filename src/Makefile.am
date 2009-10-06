AUTOMAKE_OPTIONS = gnu

AM_CPPFLAGS = $(SDL_CFLAGS) $(lua_CFLAGS) $(luabind_CFLAGS)
AM_LDFLAGS = $(SDL_LIBS) $(lua_LIBS) $(luabind_LIBS)

bin_PROGRAMS = jewels lua_test
jewels_SOURCES = jewels.cc game.cc screenobject.cc material.cc materialfactory.cc camera.cc cubicjewel.cc wobblycube.cc light.cc board.cc animator.cc animatorfactory.cc

lua_test_SOURCES = lua_test.cc animator.cc animatorfactory.cc