#ifndef BOARD_H
#define BOARD_H

#include "screenobject.h"
#include <vector>
#include <tr1/memory>


class  Board : public ScreenObject{

  unsigned x_size_;
  unsigned y_size_;
  unsigned z_size_;
  std::vector<ScreenObjectPtr> board;
public:
  Board(unsigned x_size= 8,unsigned y_size=8,unsigned z_size=1);
  ScreenObjectPtr& at(int x, int y, int z) {
    return board[z*y_size_*x_size_ + y*x_size_ + x];
  }
  int pack_name(int x, int y, int z) {
    return x*1000 + y*100 + z +1;
  }
  Point unpack_name(int name) {
    name -= 1;
    int x=name/1000;
    int y=(name%1000)/100;
    int z=(name%100);
    return Point(x,y,z);
  }
  void do_draw();
  void do_animate();
  void object_clicked(int name);
};

typedef std::tr1::shared_ptr<Board> BoardPtr;

#endif // BOARD_H
