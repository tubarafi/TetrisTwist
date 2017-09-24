#include <iostream>
#include "tDisplay.h"

using namespace std;

// Constructor
tDisplay::tDisplay(Board* gameBoard, Board* nextBlock, Level* l): gameBoard{gameBoard}, nextBlock{nextBlock}, l{l} {}

// Destructor
tDisplay::~tDisplay() {
  delete gameBoard;
  delete nextBlock;
  // delete l;
}

// Output Text Display
ostream &operator<<(ostream &out, tDisplay &td) {
  // Print stats
  out << "Level: " << (td.l)->getLevel() << endl;
  out << "Score: " << (td.l)->getCurrScore() << endl;
  out << "Hi Score: " << (td.l)->getHiScore() << endl;
  // Print divider
  for (int i = 0; i < (td.gameBoard)->getWidth(); ++i) {
    out << "-";
  }
  out << endl;
  // Print game board
  for (int i = (td.gameBoard)->getHeight() - 1; i >= 0; --i) {
    for (int j = 0; j < (td.gameBoard)->getWidth(); ++j) {
      out << ((td.gameBoard)->getCell((Coordinate){j,i}))->getBlockType();
    }
    out << endl;
  }

  // Print divider
  for (int i = 0; i < (td.gameBoard)->getWidth(); ++i) {
    out << "-";
  }
  out << endl;


  // Print next block
  out << "Next: " << endl;
  for (int i = (td.nextBlock)->getHeight() - 1; i >= 0; --i) {
    for (int j = 0; j < (td.nextBlock)->getWidth(); ++j) {
      out << ((td.nextBlock)->getCell((Coordinate){j,i}))->getBlockType();
    }
    out << endl;
  }
  return out;
}
