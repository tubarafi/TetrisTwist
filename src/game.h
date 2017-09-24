#ifndef _GAME_H_
#define _GAME_H_

#include "level.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include "board.h"
#include "block.h"
#include "cmdInterp.h"
//#include "gDisplay.h"
#include "tDisplay.h"
#include <iostream>
#include <vector>
#include <sstream>

class Game {
  int curLevel; //which level to start the game
  Board *gBoard; // game board
  Board *queueBoard; // displays block in queue
  Block *curBlock;
  Block *nextBlock;
  Level *gLevel;
  tDisplay *gTextDisplay;
//gDisplay *gGraphicsDisplay;
  CmdInterp *interpreter;

  std::vector<Block *> loBlocks;

  bool graphicsON;
  std::string scriptfile; //name of the scriptfile

  void restartGame(); // restarts the game

public:
  //constructor;
  Game(int curLevel);
  ~Game();
  void runGame();
  void isGraphicsON();
  void makeScriptfile(std::string file);
  void makeLevel(int num);
  //void levelChange(int newLevel);
  Block *spawnBlock(); //lol what is this
  void levelUp();
  void levelDown();


};

#endif
