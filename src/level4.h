#ifndef _LEVEL4_H_
#define _LEVEL4_H_

#include "block.h"
#include "board.h"
#include "level.h"

class Level4: public Level {
public:
  Level4(int currScore, int hiScore, int level);
  Block * getNextBlock(Board *boardPtr, Coordinate coordin);
};

#endif
