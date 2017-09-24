#ifndef _CELL_H_
#define _CELL_H_

class Block;

struct Coordinate {
	int x;
	int y;
};

class Cell {
	Coordinate coord;
	bool occupied;
	char blockType;
	Block* b;
public:
	Cell(Coordinate coord, bool occupied, char blockType);
	~Cell();
	// Retrieves private data
	Coordinate getCoord();
	bool isOccupied();
	char getBlockType();
	// Changes cell
	void setEmpty();
	void setOccupy(char block);
	Cell* update(char type, Coordinate newCoord, bool occupy, Block* bType);
};

#endif
