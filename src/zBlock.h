#ifndef _ZBLOCK_H_
#define _ZBLOCK_H_
#include "block.h"

class zBlock: public Block {
	static const Coordinate loStates[4][4];
  char blockType;
  Board *board;
  int colour;
public:
  // constructor
  zBlock(int levelnum, char blockType, Coordinate origin, Board *bPtr, int state, int cellnum);
};

#endif
