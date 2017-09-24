#include <vector>
#include "oneBlock.h"

using namespace std;


const Coordinate oneBlock::loStates[1][1] = {(Coordinate){6,15}};

// Constructor
oneBlock::oneBlock(int levelnum, char blockType, Coordinate origin, Board *bPtr, int state, int cellnum):
  Block(levelnum, blockType, origin, bPtr, state, cellnum) {

    colour = 9;

    for (int x = 0; x < 1; ++x) {
      // places the coordinates of all possible states of a block
       vector<Coordinate> loPosns;
       for(int y = 0; y < 1; ++y){
         loPosns.push_back(loStates[x][y]);
       }
       loCoords[x] = loPosns;
       loPosns.clear();
    }

}