#ifndef _TDISPLAY_H_
#define _TDISPLAY_H_

#include <iostream>
#include "level.h"
#include "board.h"
#include "block.h"
class Level;

class tDisplay {
  Board* gameBoard;
  Board* nextBlock;
  Level* l;
public:
  tDisplay(Board* gameBoard, Board* nextBlock, Level* l);
  ~tDisplay();
  friend std::ostream& operator<<(std::ostream &out, tDisplay &td);
};

#endif
