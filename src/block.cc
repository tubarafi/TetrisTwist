#include "block.h"
#include <iostream>
using namespace std;


// Constructor
Block::Block(int levelnum, char blockType, Coordinate origin, Board *bPtr, int state, int cellnum) : levelnum{levelnum},
	blockType{blockType}, origin{origin}, bPtr{bPtr}, state{0}, cellnum{cellnum} {}


// Destructor
Block::~Block(){} //empty destructor


// Updates block when a cell is cleared
void Block::clearCell(Level &lRef){
	--cellnum;
	//updates score in Level when a whole block is cleared
	if (cellnum == 0){
		int addScore = (levelnum + 1) * (levelnum + 1);
		lRef.updateCurrScore(addScore);
	}
}


// Checks if cell at given coordinates is occupied
bool Block::checkPos(Coordinate thisCoord){
	return bPtr->getCell(thisCoord)->isOccupied();
}


// Checks if there is space to place block in initial position
bool Block::checkInit(){
	for (int i = 0; i < 4; ++i){
		Coordinate curPos = loCoords[state][i];
		if(checkPos(curPos)){
			return false;
		}
	}
	return true;
}


// Initializes starting block
void Block::initBoard(Board *bP){
	origin.x = 0;
	origin.y = 0;
	bPtr = bP;
	loCells.clear();
	for (int i = 0; i < 4; ++i){
		Coordinate curPos = loCoords[state][i];
		Cell* curCell = bPtr->getCell(curPos);
		loCells.push_back(curCell->update(blockType, curPos, true, this));
	}
}

// Checks if block can move down one row
bool Block::checkDown (){
	for (list<Cell*>::iterator thisCell = loCells.begin(); thisCell !=loCells.end(); ++thisCell){
		Coordinate thisCoord = (*thisCell)->getCoord();
		if (thisCoord.y == 0) {
			return false;
		}
		thisCoord.y -= 1;
		if (checkPos(thisCoord)) {
			return false;
		}
	}
	return true;
}

// Moves block down one row
void Block::goDown(){
	for (list<Cell*>::iterator thisCell = loCells.begin(); thisCell !=loCells.end(); ++thisCell){
		(*thisCell)->setEmpty();
	}
	if (!checkDown()) {
		for (list<Cell*>::iterator thisCell = loCells.begin(); thisCell !=loCells.end(); ++thisCell){
			(*thisCell)->setOccupy(blockType);
		}
		return;
	}
	Cell *newCell;
	for (list<Cell*>::iterator thisCell = loCells.begin(); thisCell !=loCells.end(); ++thisCell){
		Coordinate prevPos = (*thisCell)->getCoord();
		Coordinate newPos = prevPos;
		newPos.y -= 1;
		newCell = bPtr->getCell(newPos);
		(*thisCell) = newCell->update(blockType, newPos, true, this);
	}

	origin.y += 1;

	// if block is heavy
	if (levelnum > 2){
		goDown();
	}
}

// Checks if block can move to the left one column
bool Block::checkLeft (){
	for (list<Cell*>::iterator thisCell = loCells.begin(); thisCell !=loCells.end(); ++thisCell){
		Coordinate thisCoord = (*thisCell)->getCoord();
		if (thisCoord.x == 0) {
			return false;;
		}
		thisCoord.x -= 1;
		if (checkPos(thisCoord)) {
			return false;
		}
	}
	return true;
}

// Moves the block one column to the left
void Block::goLeft() {
	for (list<Cell*>::iterator thisCell = loCells.begin(); thisCell !=loCells.end(); ++thisCell){
		(*thisCell)->setEmpty();
	}
	if (!checkLeft()) {
		for (list<Cell*>::iterator thisCell = loCells.begin(); thisCell !=loCells.end(); ++thisCell){
			(*thisCell)->setOccupy(blockType);
		}
		return;
	}
	Cell *newCell;
	for (list<Cell*>::iterator thisCell = loCells.begin(); thisCell !=loCells.end(); ++thisCell){
		Coordinate prevPos = (*thisCell)->getCoord();
		Coordinate newPos = prevPos;
		newPos.x -= 1;
		newCell = bPtr->getCell(newPos);
		(*thisCell) = newCell->update(blockType, newPos, true, this);
	}
	origin.x -= 1;

	// if block is heavy
	if (levelnum > 2){
		goDown();
	}
}





// Checks if block can move to the right one column
bool Block::checkRight (){
	//int width = bPtr->getWidth();
	int width = bPtr->getWidth();
	for (list<Cell*>::iterator thisCell = loCells.begin(); thisCell !=loCells.end(); ++thisCell){
		Coordinate thisCoord = (*thisCell)->getCoord();
		if (thisCoord.x == width - 1) {
			return false;;
		}
		thisCoord.x += 1;
		if (checkPos(thisCoord)) {
			return false;
		}
	}
		return true;
}

// Moves the block one column to the right
void Block::goRight(){
	for (list<Cell*>::iterator thisCell = loCells.begin(); thisCell !=loCells.end(); ++thisCell){
		(*thisCell)->setEmpty();
	}
	if (!checkRight()) {
		for (list<Cell*>::iterator thisCell = loCells.begin(); thisCell !=loCells.end(); ++thisCell){
			(*thisCell)->setOccupy(blockType);
		}
		return;
	}
	Cell *newCell;
	for (list<Cell*>::iterator thisCell = loCells.begin(); thisCell !=loCells.end(); ++thisCell){
		Coordinate prevPos = (*thisCell)->getCoord();
		Coordinate newPos = prevPos;
		newPos.x += 1;
		newCell = bPtr->getCell(newPos);
		(*thisCell) = newCell->update(blockType, newPos, true, this);
	}

	origin.x += 1;

	// if block is heavy
	if (levelnum > 2){
		goDown();
	}
}


int Block::newStateCW(int prevState){
	if (prevState == 3){
		return 0;
	}
	else {
		return ++prevState;
	}
}


int Block::newStateCCW(int prevState){
	if (prevState == 0){
		return 3;
	}
	else {
		return --prevState;
	}
}


bool Block::checkRotate(int dir){
	int width = bPtr->getWidth();
	int newState;
	if (dir == 0){
		newState = newStateCW(state);
	} else {
		newState = newStateCCW(state);
	}
	for (int i = 0; i < 4; ++i){
		Coordinate thisCoord;
		thisCoord.x = (loCoords[newState][i]).x + origin.x;
		thisCoord.y = (loCoords[newState][i]).y - origin.y;
		if (checkPos(thisCoord)){
			return false;
		}
		// check if rotating the block makes it go over the board border
		if (thisCoord.x > width || thisCoord.x < 0){
			return false;
		}
		if (thisCoord.y < 0){
			return false;
		}
	}
	return true;
}


void Block::rotate(int dir){
	for (list<Cell*>::iterator thisCell = loCells.begin(); thisCell !=loCells.end(); ++thisCell){
		(*thisCell)->setEmpty();
	}
	if (!checkRotate(dir)) {
		for (list<Cell*>::iterator thisCell = loCells.begin(); thisCell !=loCells.end(); ++thisCell){
			(*thisCell)->setOccupy(blockType);
		}
		return;
	} else {
		if (dir == 0) {
			state = newStateCW(state);
		}
		else {
			state = newStateCCW(state);
		}
	}
	Cell *newCell;
	int i = 0;
	for (list<Cell*>::iterator thisCell = loCells.begin(); thisCell != loCells.end(); ++thisCell){
		Coordinate newPos;
			newPos.x = (loCoords[state][i]).x + origin.x;
			newPos.y = (loCoords[state][i]).y - origin.y;
			newCell = bPtr->getCell(newPos);
			(*thisCell) = newCell->update(blockType, newPos, true, this);
			++i;
		}


	// if block is heavy
	if (levelnum > 2){
		goDown();
	}
}


void Block::drop(){
	int height = bPtr->getHeight();
	int max = height;
	for (list<Cell*>::iterator thisCell = loCells.begin(); thisCell !=loCells.end(); ++thisCell){
		(*thisCell)->setEmpty();
	}
	for (list<Cell*>::iterator thisCell = loCells.begin(); thisCell !=loCells.end(); ++thisCell){
		int tempMax = 0;
		Coordinate thisCoord = (*thisCell)->getCoord();
		Coordinate tempCoord = thisCoord;
		tempCoord.y -= 1;
		while (tempCoord.y >= 0) {
			if (checkPos(tempCoord)) {
				break;
			} else {
				--tempCoord.y;
				++tempMax;
			}
		}
		if (tempMax < max){
			max = tempMax;
		}
	}

	// If there is no space to drop, exit
	if (max == 0){
		for (list<Cell*>::iterator thisCell = loCells.begin(); thisCell !=loCells.end(); ++thisCell){
			(*thisCell)->setOccupy(blockType);
		}
		return;
	}
	//vector<Coordinate> loNewPos;
	Cell *newCell;
	for (list<Cell*>::iterator thisCell = loCells.begin(); thisCell !=loCells.end(); ++thisCell){
		(*thisCell)->setEmpty();
		Coordinate prevPos = (*thisCell)->getCoord();
		Coordinate newPos = prevPos;
		newPos.y -= max;
		if (newPos.y > (height - 3)){
			return;
			//return false; call gameFinished?
		}
		newCell = bPtr->getCell(newPos);
		(*thisCell) = newCell->update(blockType, newPos, true, this);

	}

	origin.y -= max;
	//return true;
}

bool Block::checkContinue() {
	if ((this->checkDown() == false) && (this->checkLeft() == false) && (this->checkRight() == false)){
		if (this->checkRotate(0) == false){
			return false;
		}
	}
	return true;
}

// Used to make nextBlock the next curBlock
Block& Block::operator =(Block &other) {
	levelnum = other.levelnum;
	blockType = other.blockType;
	origin = other.origin;
	contGame = other.contGame;
	state = other.state;
	cellnum = other.cellnum;
	colour = other.colour;
	return *this;
}


/*
void Block::draw(gDisplay *gd, int boardType) {
	for (list<Cell*>::iterator thisCell = loCells.begin(); thisCell !=loCells.end(); ++thisCell) {
		int x = ((*thisCell)->getCoord()).x;
		int y = ((*thisCell)->getCoord()).y;
		int board = boardType;
		gd->drawCell(x, y, colour, boardType);
	}
}


void Block::undraw(gDisplay *gd, int boardType) {
	for (list<Cell*>::iterator thisCell = loCells.begin(); thisCell !=loCells.end(); ++thisCell) {
		int x = ((*thisCell)->getCoord()).x;
		int y = ((*thisCell)->getCoord()).y;
		gd->undrawCell(x, y, boardType);
	}
}
*/
