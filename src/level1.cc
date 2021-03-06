#include "level1.h"
#include "block.h"
#include "jBlock.h"
#include "iBlock.h"
#include "lBlock.h"
#include "tBlock.h"
#include "zBlock.h"
#include "oBlock.h"
#include "sBlock.h"

#include <iostream>

using namespace std;

Level1::Level1(int currScore, int hiScore, int level):Level(currScore, hiScore, level) {}

Block * Level1::getNextBlock(Board *boardPtr, Coordinate coordin) {
    int prob = rand() % 12;
    if (prob == 0 || prob == 1) {
      return new jBlock(getLevel(), 'J', coordin, boardPtr, 0, 4);
    }
    else if (prob == 2 || prob == 3) {
      return new iBlock(getLevel(), 'I', coordin, boardPtr, 0, 4);
    }
    else if (prob == 4 || prob == 5) {
      return new lBlock(getLevel(), 'L', coordin, boardPtr, 0, 4);
    }
    else if (prob == 6) {
      return new sBlock(getLevel(), 'S', coordin, boardPtr, 0, 4);
    }
    else if (prob == 7 || prob == 8) {
      return new tBlock(getLevel(), 'T', coordin, boardPtr, 0, 4);
    }
    else if (prob == 9) {
      return new zBlock(getLevel(), 'Z', coordin, boardPtr, 0, 4);
    }
    else {
      return new oBlock(getLevel(), 'O', coordin, boardPtr, 0, 4);
    }
}
