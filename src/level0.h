#ifndef _LEVEL0_H_
#define _LEVEL0_H_

#include "block.h"
#include "board.h"
#include "level.h"
#include <string>


class Level0: public Level {
	static int counter;
	std::vector<std::string> loBlocks;

public:
  Level0(int currScore, int hiScore, int level);
  Block *getNextBlock(Board *boardPtr, Coordinate coordin) override;
};

#endif
