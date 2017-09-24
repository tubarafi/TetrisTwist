#ifndef _LEVEL2_H_
#define _LEVEL2_H_

#include "block.h"
#include "board.h"
#include "level.h"

class Level2: public Level {
public:
  Level2(int currScore, int hiScore, int level);
  Block * getNextBlock(Board *boardPtr, Coordinate coordin);
};

#endif
