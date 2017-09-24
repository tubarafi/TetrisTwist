#ifndef _SBLOCK_H_
#define _SBLOCK_H_
#include "block.h"

class sBlock: public Block  {
	static const Coordinate loStates[4][4];
	char blockType;
	Board *board;
	int colour;
public:
	// constructor
	sBlock(int levelnum, char blockType, Coordinate origin, Board *bPtr, int state, int cellnum);
};

#endif
