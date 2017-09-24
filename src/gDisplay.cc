#include <string>
#include <sstream>
#include "gDisplay.h"

using namespace std;

// Constructor
gDisplay::gDisplay(Board* gameBoard, Board* nextBlock, int cellSize, int numRow, int numCol, int buffer):
gameBoard{gameBoard}, nextBlock{nextBlock}, cellSize{cellSize}, numRow{numRow}, numCol{numCol}, buffer{buffer} {
  int wWidth = cellSize * (numCol + buffer * 2);  // Window width
  int wHeight = cellSize * (numRow + buffer * 2);  // Window height
}

// buffer is the number of lines that you would like between the window border and the first/last line
// Destructor
gDisplay::~gDisplay() {
  delete window;
}

// Initializes starting game board
void gDisplay::initialize() {
  xw = new Xwindow(wWidth, wHeight);
  // Initialize background to white
  xw->fillRectangle(0, 0, wWidth, wHeight, 0);
  // Print starting text
  xw->drawString(30 * cellSize, 2 * cellSize, "Level: ", 1);
  xw->drawString(30 * cellSize, 3 * cellSize, "Score: " , 1);
  xw->drawString(30 * cellSize, 4 * cellSize, "Hi Score: ", 1);
  xw->drawString(42 * cellSize, 2 * cellSize, "0", 1);  // Displays level as 0
  xw->drawString(42 * cellSize, 3 * cellSize, "0", 1);  // Displays starting score
  xw->drawString(42 * cellSize, 4 * cellSize, "0", 1);  // Displays current hi score
  xw->drawString(30 * cellSize, (wHeight - buffer) * cellSize, "Next: ", 1);
}

// Updates level shown
void gDisplay::updateLevel(int nlevel) {
  // Convert the level integer to string type
  stringstream ss;
  ss << nlevel;
  string level;
  ss >> level;
  // Erase old level
  xw->fillRectangle(42 * cellSize, 2 * cellSize, cellSize, cellSize, 1);
  // Print new level
  xw->drawString(42 * cellSize, 2 * cellSize, level, 1);
}

// Updates current score shown
void gDisplay::updateCurrScore(int nscore) {
  // Convert the score integer to string type
  stringstream ss;
  ss << nscore;
  string score;
  ss >> score;
  // Erase old score
  // Figure out length of printed score
  int temp = nscore;
  int digitCount = 0;
  while (temp != 0) {
    temp /= 10;
    ++digitCount;
  }
  xw->fillRectangle(42 * cellSize, 3 * cellSize, cellSize, cellSize * digitCount, 1);
  // Print new score
  xw->drawString(42 * cellSize, 3 * cellSize, score, 1);
}

// Updates current hi score shown
void gDisplay::updateHiScore(int nscore) {
  // Convert the score integer to string type
  stringstream ss;
  ss << nscore;
  string score;
  ss >> score;
  // Erase old score
  // Figure out length of printed score
  int temp = nscore;
  int digitCount = 0;
  while (temp != 0) {
    temp /= 10;
    ++digitCount;
  }
  xw->fillRectangle(42 * cellSize, 4 * cellSize, cellSize, cellSize * digitCount, 1);
  // Print new score
  xw->drawString(42 * cellSize, 4 * cellSize, score, 1);
}

// Draws the board
void gDisplay::drawBlankBoard() {
  xw->fillRectangle(30 * cellSize, 6 * cellSize, numCol * cellSize, numRow * cellSize, 1);
}

// Draws a cell in the corresponding colour at the given position
void gDisplay::drawCell(int x, int y, int colour, int boardType){
  if (boardType == 0) {
    xw->fillRectangle((30 + x) * cellSize, (wHeight - buffer - y) * cellSize, cellSize, cellSize, colour);
  }
  else {
    xw->fillRectangle((30 + x) * cellSize, (buffer - y) * cellSize, cellSize, cellSize, colour);
  }
}

// Undraws a cell at the given position
void gDisplay::undrawCell(int x, int y, int boardType) {
  if (boardType == 0) {
    xw->fillRectangle((30 + x) * cellSize, (wHeight - buffer - y) * cellSize, cellSize, cellSize, 2);
  }
  else {
    xw->fillRectangle((30 + x) * cellSize, (buffer - y) * cellSize, cellSize, cellSize, 2);
  }
}
