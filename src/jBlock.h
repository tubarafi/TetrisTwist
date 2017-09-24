#ifndef _JBLOCK_H_
#define _JBLOCK_H_
#include "block.h"

class jBlock: public Block  {
	static const Coordinate loStates[4][4];
  char blockType;
  Board *board;
  int colour;
public:
  jBlock(int levelnum, char blockType, Coordinate origin, Board *bPtr, int state, int cellnum);
};

#endif
