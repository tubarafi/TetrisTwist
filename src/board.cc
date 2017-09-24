#include <map>
#include <vector>
#include <list>
#include "board.h"
#include <iostream>

using namespace std;

// Constructor
Board::Board(int row, int col): height{row}, width{col} {
  // Allocates memory for cells on the board
  grid = new Cell**[width];
  for (int i = 0; i < width; ++i) {
    grid[i] = new Cell*[height];
    for (int j = 0; j < height; ++j) {
      grid[i][j] = new Cell((Coordinate){i,j}, false, ' ');
    }
  }
}

// Destructors
Board::~Board() {
  for (int i = 0; i < width; ++i) {
    for (int j = 0; j < height; ++j) {
      delete grid[i][j];
    }
    delete[] grid[i];
  }
  delete[] grid;
}

// Resets the board
void Board::reset() {
  for (int i = 0; i < width; ++i) {
    for (int j = 0; j < height; ++j) {
      if (grid[i][j]->isOccupied()) {
        grid[i][j]->setEmpty();
      }
    }
  }
}

// Retrieves the height of the board
int Board::getWidth() {
  return width;
}

// Retrieves the height of the board
int Board::getHeight() {
  return height;
}

// Retrieve coordinates of cell
Cell* Board::getCell(Coordinate coord) {
  return (grid[coord.x][coord.y]);
}

// Shifts the portion of the board above the replace row down one row
void Board::moveDown(int replace) {
  for (int i = 0; i < width; ++i) {
    for (int j = replace + 1; j < height; ++j) {
      char newBlockType = grid[i][j]->getBlockType();
      grid[i][j - 1]->setOccupy(newBlockType);
      grid[i][j]->setEmpty();
    }
  }
}

// Checks if line is filled
bool Board::isRowFull(int row) {
  for (int i = 0; i < width; ++i) {
    if (!(grid[i][row]->isOccupied())) {
      return false;
    }
  }
  return true;
}

// Clears a filled line
void Board::clearFullLines(Level &l) {
  int rowsCleared = 0;
  for (int x = 0; x < height; ++x) {
    // Clears filled rows and updates rowsCleared
    if (isRowFull(x)) {
      ++rowsCleared;
      moveDown(x);
      cout << x << endl;
    }
  }
  if (rowsCleared > 0){
    int score = ((l.getLevel()) + rowsCleared) * ((l.getLevel()) + rowsCleared);
    l.updateCurrScore(score);
    l.updateHiScore();
  }
}
