#ifndef _GDISPLAY_H_
#define _GDISPLAY_H_

#include "window.h"


class Board;

class Xwindow;

class gDisplay {
  Xwindow* xw;
  Board* gameBoard;
  Board* nextBlock;
  int cellSize;
  int numRow;
  int numCol;
  int buffer;
  int wWidth;
  int wHeight;
public:
  gDisplay(Board* gameBoard, Board* nextBlock, int cellSize = 30, int numRow = 18, int numCol = 11, int buffer = 5);
  ~gDisplay();
  void initialize();
  // Updates strings on display
  void updateLevel(int nlevel);
  void updateCurrScore(int nscore);
  void updateHiScore(int nscore);
  // Updates board on display
  void drawBlankBoard();
  void drawCell(int x, int y, int colour, int boardType);
  void undrawCell(int x, int y, int boardType);
};

#endif
