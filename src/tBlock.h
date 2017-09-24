#ifndef _TBLOCK_H_
#define _TBLOCK_H_
#include "block.h"

class tBlock: public Block {
	static const Coordinate loStates[4][4];
  char blockType;
  Board *board;
  int colour;
public:
  // constructor
  tBlock(int levelnum, char blockType, Coordinate origin, Board *bPtr, int state, int cellnum);
};

#endif
