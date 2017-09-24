#include "level0.h"
#include "block.h"
#include "jBlock.h"
#include "iBlock.h"
#include "lBlock.h"
#include "tBlock.h"
#include "zBlock.h"
#include "oBlock.h"
#include "sBlock.h"
#include <fstream>
#include <iostream>

using namespace std;

Level0::Level0(int currScore, int hiScore, int level):Level(currScore, hiScore, level) {
  ifstream cmds {"sequence.txt"};
  string s;
  while (cmds >> s){
    loBlocks.push_back(s);
  }
}


int Level0::counter = 0;


Block * Level0::getNextBlock(Board *boardPtr, Coordinate coordin) {
    if (counter == 7){
      counter = 0;
    }
    if (loBlocks.at(counter) == "J") {
      ++counter;
      return new jBlock(getLevel(), 'J', coordin, boardPtr, 0, 4);
    }
    else if (loBlocks.at(counter) == "I") {
      ++counter;
      return new iBlock(getLevel(), 'I', coordin, boardPtr, 0, 4);
    }
    else if (loBlocks.at(counter) == "L") {
      ++counter;
      return new lBlock(getLevel(), 'L', coordin, boardPtr, 0, 4);
    }
    else if (loBlocks.at(counter) == "S") {
      ++counter;
      return new sBlock(getLevel(), 'S', coordin, boardPtr, 0, 4);
    }
    else if (loBlocks.at(counter) == "T") {
      ++counter;
      return new tBlock(getLevel(), 'T', coordin, boardPtr, 0, 4);
    }
    else if (loBlocks.at(counter) == "Z") {
      ++counter;
      return new zBlock(getLevel(), 'Z', coordin, boardPtr, 0, 4);
    }
    else {
      ++counter;
      return new oBlock(getLevel(), 'O', coordin, boardPtr, 0, 4);
    }
}
