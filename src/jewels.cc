#include <iostream>
#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"

#include "game.h"
#include "materialfactory.h"

#define SCR_WIDTH  640
#define SCR_HEIGHT 480


int main(int argc, char *argv[]) {
  std::cout << "Starting...\n";

  if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ){
    std::cout << "Failed to initialize SDL!";
    return -1;
  }

  SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 5 );
  SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 5 );
  SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 5 );
  SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
  SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

  if( SDL_SetVideoMode( SCR_WIDTH, SCR_HEIGHT, 0, SDL_OPENGL ) == NULL ) {
    std::cout << "Failed to set video mode SDL!";
    return -1;
  };

  SDL_Event event;

  //MaterialFactory::print_materials();

  Game game;
  game.setup_screen(SCR_WIDTH,SCR_HEIGHT);
  while ( !game.end_game() ) {
    while( SDL_PollEvent( &event ) ) {
      if( event.type == SDL_QUIT ){
        game.set_end_game(true);
      }
      if(event.type == SDL_KEYDOWN ){
        SDL_KeyboardEvent* ev=reinterpret_cast<SDL_KeyboardEvent*>(&event);
        if( ev->keysym.sym == SDLK_ESCAPE ){
          game.set_end_game(true);
        }
      }
      if( event.type == SDL_MOUSEBUTTONDOWN){
        SDL_MouseButtonEvent* ev=reinterpret_cast<SDL_MouseButtonEvent*>(&event);
        if( ev->button == SDL_BUTTON_LEFT && ev->state == SDL_PRESSED ) {
          std::cout <<  "Mouse down at " << ev->x << "," <<ev->y << std::endl;
          game.left_button_down(ev->x,SCR_HEIGHT - ev->y);
        }
      }
    }
    game.draw_scene();
    game.animate();
    SDL_GL_SwapBuffers( );

    SDL_Delay( 50 );
  }

 SDL_Quit();
 return 0;
}
