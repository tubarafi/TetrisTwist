#ifndef _IBLOCK_H_
#define _IBLOCK_H_
#include "block.h"

class iBlock: public Block {
	//static const Coordinate loStates[4][4];
	char blockType;
	Board *board;
	int colour;

public:
	// constructor
	iBlock(int levelnum, char blockType, Coordinate origin, Board *bPtr, int state, int cellnum);
};

#endif
