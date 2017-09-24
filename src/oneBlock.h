#ifndef _ONEBLOCK_H_
#define _ONEBLOCK_H_
#include "block.h"


class oneBlock: public Block{
	static const Coordinate loStates[1][1];
	char blockType;
	Board *board;
	int colour;
public:
	//constructor
	oneBlock(int levelnum, char blockType, Coordinate origin, Board *bPtr, int state, int cellnum);
};

#endif
