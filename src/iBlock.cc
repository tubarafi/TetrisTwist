#include <vector>
#include "iBlock.h"

using namespace std;

// list of possible states
/*
 Coordinate iBlock::loStates[4][4] =
  /*{{(Coordinate){0,14}, (Coordinate){1,14}, (Coordinate){2,14}, (Coordinate){3,14}},
   {(Coordinate){0,17}, (Coordinate){0,16}, (Coordinate){0,15}, (Coordinate){0,14}},
   {(Coordinate){0,14}, (Coordinate){1,14}, (Coordinate){2,14}, (Coordinate){3,14}},
   {(Coordinate){0,17}, (Coordinate){0,16}, (Coordinate){0,15}, (Coordinate){0,14}}};
   {{(Coordinate){0,3}, (Coordinate){1,3}, (Coordinate){2,3}, (Coordinate){3,3}},
    {(Coordinate){0,0}, (Coordinate){0,1}, (Coordinate){0,2}, (Coordinate){0,3}},
    {(Coordinate){0,3}, (Coordinate){1,3}, (Coordinate){2,3}, (Coordinate){3,3}},
    {(Coordinate){0,0}, (Coordinate){0,1}, (Coordinate){0,2}, (Coordinate){0,3}}}; */


// Constructor
iBlock::iBlock(int levelnum, char blockType, Coordinate origin, Board *bPtr, int state, int cellnum):
Block(levelnum, blockType, origin, bPtr, state, cellnum) {
  colour = 5;

  vector <vector<Coordinate>> loStates =
    {{{0,3}, {1,3}, {2,3}, {3,3}},
     {{0,3}, {0,4}, {0,5}, {0,6}},
     {{0,3}, {1,3}, {2,3}, {3,3}},
     {{0,3}, {0,4}, {0,5}, {0,6}}};

    for (int x = 0; x < 4; ++x){
      if (bPtr->getHeight() == 4){
        loCoords[x] = loStates[x];
      } else {
        for (int y = 0; y < 4; ++y){
          ((loStates[x][y]).y) += (bPtr->getHeight() - 7);
        }
          loCoords[x] = loStates[x];
      }
    }
  }
    /*Coordinate loStates[4][4] =
      {{(Coordinate){0,3}, (Coordinate){1,3}, (Coordinate){2,3}, (Coordinate){3,3}},
       {(Coordinate){0,0}, (Coordinate){0,1}, (Coordinate){0,2}, (Coordinate){0,3}},
       {(Coordinate){0,3}, (Coordinate){1,3}, (Coordinate){2,3}, (Coordinate){3,3}},
       {(Coordinate){0,0}, (Coordinate){0,1}, (Coordinate){0,2}, (Coordinate){0,3}}};

    for (int x = 0; x < 4; ++x){
      if (bPtr->getHeight() == 4){
        loCoords[x] = loStates[x];
      } else {
        for (int y = 0; y < 4; ++y){
          ((loStates[x][y]).y) += (bPtr->getHeight() - 7);
        }
          loCoords[x] = loStates[x];
      }
    }
}
*/
