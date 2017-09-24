#ifndef _LEVEL_H_
#define _LEVEL_H_

#include "block.h"
#include "board.h"

class Block;
class Board;

class Level {
  int currScore;
  int hiScore;
  int level;
public:
  Level(int currScore, int hiScore, int level);
  ~Level();
  int getCurrScore();
  int getHiScore();
  void resetScore();
  void updateHiScore();
  int getLevel();
  void updateLevel(int newLevel);
  void updateCurrScore(int points);
  virtual Block *getNextBlock(Board *boardPtr, Coordinate coordin) = 0;
};


#endif
