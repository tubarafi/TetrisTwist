#include <vector>
#include "oBlock.h"

using namespace std;

// list of possible states
const Coordinate oBlock::loStates[4][4] =
  {{(Coordinate){0,15}, (Coordinate){0,14}, (Coordinate){1,15}, (Coordinate){1,14}},
   {(Coordinate){0,15}, (Coordinate){0,14}, (Coordinate){1,15}, (Coordinate){1,14}},
   {(Coordinate){0,15}, (Coordinate){0,14}, (Coordinate){1,15}, (Coordinate){1,14}},
   {(Coordinate){0,15}, (Coordinate){0,14}, (Coordinate){1,15}, (Coordinate){1,14}}};

// Constructor
oBlock::oBlock(int levelnum, char blockType, Coordinate origin, Board *bPtr, int state, int cellnum):
  Block(levelnum, blockType, origin, bPtr, state, cellnum) {
    colour = 6;

    for (int x = 0; x < 4; ++x) {
      // places the coordinates of all possible states of a block
       vector<Coordinate> loPosns;
       for(int y = 0; y < 4; ++y){
         loPosns.push_back(loStates[x][y]);
       }
       loCoords[x] = loPosns;
       loPosns.clear();
    }
}
