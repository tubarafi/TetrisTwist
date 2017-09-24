#ifndef _LEVEL1_H_
#define _LEVEL1_H_

#include "block.h"
#include "board.h"
#include "level.h"

class Level1: public Level {
public:
  Level1(int currScore, int hiScore, int level);
  Block * getNextBlock(Board *boardPtr, Coordinate coordin);
};

#endif
