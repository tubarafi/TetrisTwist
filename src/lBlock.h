#ifndef _LBLOCK_H_
#define _LBLOCK_H_
#include "block.h"

class lBlock: public Block  {
	static const Coordinate loStates[4][4];
  char blockType;
  Board *board;
  int colour;
public:
  lBlock(int levelnum, char blockType, Coordinate origin, Board *bPtr, int state, int cellnum);
};

#endif
