#ifndef _BOARD_H_
#define _BOARD_H_

#include "cell.h"
#include "level.h"
class Level;

class Board {
	Cell*** grid;
	int height;
	int width;
public:
	Board(int row, int col);
	~Board();
	void reset();
	// Retrieve private data
	int getWidth();
	int getHeight();
	Cell* getCell(Coordinate coord);
	// Changes to cell occupancy on Board
	void moveDown(int replace);
	bool isRowFull (int row);
	void clearFullLines(Level &l);
	// Level 5 feature
};

#endif
