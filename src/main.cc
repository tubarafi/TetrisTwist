#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

#include "game.h"

using namespace std;


int main (int argc, char* argv[]) {

  int levNum = 0;

  Game *newGame = new Game(levNum);

  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i],"-text") == 0) {
      newGame->isGraphicsON();
    }
    else if (strcmp(argv[i],"-seed") == 0) {
      int seedNum;
      stringstream seedStream(argv[i+1]);
      seedStream >> seedNum;
      srand(seedNum);
    }
    else if (strcmp(argv[i],"-scriptfile") == 0) {
      newGame->makeScriptfile(argv[i+1]);
    }
    else if (strcmp(argv[i],"-startlevel") == 0) {
      istringstream numStream(argv[i+1]);
      numStream >> levNum;
      cout << levNum << endl;
      newGame->makeLevel(levNum);
    }
    // if no startlevel is provided, default to level 0
    else if (i == argc - 1) {
      levNum = 0;
    }
  }
  newGame->runGame();
  delete newGame;

}
