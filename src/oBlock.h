#ifndef _OBLOCK_H_
#define _OBLOCK_H_
#include "block.h"

class oBlock: public Block  {
	static const Coordinate loStates[4][4];
  char blockType;
  Board *board;
  int colour;
public:
  oBlock(int levelnum, char blockType, Coordinate origin, Board *bPtr, int state, int cellnum);
};

#endif
