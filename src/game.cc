#include "game.h"
#include "SDL/SDL_opengl.h"

#include <climits>

Game::Game():
  end_game_(false)
{
  board = BoardPtr( new Board() );
  camera.eye() = Point(0,0,-4.0);
  light.pos() = Point(0,0,25.5);
}

Game::~Game() {
}

void Game::setup_screen(int width,int height) {
  screen_width_=width;
  screen_height_=height;
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);

  glViewport( 0, 0, width, height );

	glMatrixMode(GL_PROJECTION);
	gluPerspective(60, float(width)/float(height), 0.1, 100);

	glEnable(GL_LIGHTING);
	//glEnable(GL_COLOR_MATERIAL);
	glDisable(GL_COLOR_MATERIAL);

	glMatrixMode(GL_MODELVIEW);
  light.setup();
};

void Game::draw_scene(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
  light.apply();
	camera.apply();
	board->draw();
}

void Game::animate() {
	board->animate();
}


int Game::select_from_scene(int x, int y){
  unsigned select_buffer[128];
  glSelectBuffer(128,select_buffer);
  int view[4];
  glGetIntegerv(GL_VIEWPORT,view);

  glRenderMode(GL_SELECT);
  glInitNames();
  glPushName(-1);


  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  gluPickMatrix(x, y, 1.0, 1.0, view);
  gluPerspective(60.0, float(screen_width_)/float(screen_height_), 0.1, 100);

  glMatrixMode(GL_MODELVIEW);

  draw_scene();

  glMatrixMode(GL_PROJECTION);
  glPopMatrix();

  glMatrixMode(GL_MODELVIEW);

  int hits = glRenderMode(GL_RENDER);


  int selected_name = -1;
  unsigned int min_z=UINT_MAX;
  for (int i = 0; i < hits; i++) {
    int n = select_buffer[i * 4];
    int z1 = select_buffer[i * 4 + 1];
    int z2 = select_buffer[i * 4 + 2];
    int name  = select_buffer[i * 4 + 3];
    if( z1 < min_z) {
      selected_name = name;
    }
  }
  return selected_name;
}

void Game::left_button_down(int x,int y){
  int obj = select_from_scene(x,y);
  if( obj >=0 ) {
    board->object_clicked(obj);
  }
}

