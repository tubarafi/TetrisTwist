#include "cell.h"

// Constructor
Cell::Cell(Coordinate coord, bool occupied, char blockType): coord{coord}, occupied{occupied}, blockType{blockType} {}

// Destructor
Cell::~Cell() {}

// Returns coordinates of cell
Coordinate Cell::getCoord() {
	return coord;
}

// Checks if cell is occupied
bool Cell::isOccupied() {
	return occupied;
}

char Cell::getBlockType() {
	return blockType;
}

// Changes occupied cell to empty cell
void Cell::setEmpty() {
	occupied = false;
	blockType = ' ';
}

// Changes occupied cell to occupied cell
void Cell::setOccupy(char block) {
	occupied = true;
	blockType = block;
}

// Updates properties of cell
Cell* Cell::update(char cType, Coordinate newCoord, bool occupy, Block* bType) {
	blockType = cType;
	coord = newCoord;
	occupied = occupy;
	b = bType;
	return this;
}
