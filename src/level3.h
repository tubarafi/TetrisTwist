#ifndef _LEVEL3_H_
#define _LEVEL3_H_

#include "block.h"
#include "board.h"
#include "level.h"

class Level3: public Level {
public:
  Level3(int currScore, int hiScore, int level);
  Block * getNextBlock(Board *boardPtr, Coordinate coordin);
};


#endif
