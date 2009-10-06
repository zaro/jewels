#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "camera.h"
#include "light.h"

class Game {
  bool end_game_;
  int screen_width_;
  int screen_height_;
  BoardPtr board;
  Camera camera;
  Light light;
public:
  Game();
  ~Game();
  bool end_game() { return end_game_; }
  void set_end_game(bool end_game) { end_game_ = end_game; }
  void setup_screen(int width,int height);
  void draw_scene();
  void animate();
  int  select_from_scene(int x, int y);
  void left_button_down(int x,int y);
};

#endif // GAME_H
