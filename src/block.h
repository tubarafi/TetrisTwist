#ifndef _BLOCK_H_
#define _BLOCK_H_

#include <map>
#include <vector>
#include <list>
#include "cell.h"
#include "board.h"
#include "level.h"
//#include "gDisplay.h"
class Board;
class Level;

class Block {
protected:
	int levelnum;
	char blockType;
	Coordinate origin;
	Board *bPtr;
	bool contGame;
	int state;
	int cellnum;
	int colour;
	std::map <int, std::vector<Coordinate>> loCoords;
	std::list<Cell*> loCells;

public:
	Block(int levelnum, char blockType, Coordinate origin, Board *bPtr, int state, int cellnum);
	~Block();
	void clearCell(Level &lRef);
	bool checkPos(Coordinate thisCoord);
	bool checkInit();
	void initBoard(Board *bP);
	bool checkDown();
	void goDown();
	bool checkLeft();
	void goLeft();
	bool checkRight();
	void goRight();
	int newStateCW(int prevState);
	int newStateCCW(int prevState);
	bool checkRotate(int dir);
	void rotate(int dir);
	void drop();
	bool checkContinue();
	Block &operator =(Block &other);
//	void draw(gDisplay *gd, int boardType);
//	void undraw(gDisplay *gd, int boardType);
};

#endif
