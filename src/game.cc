#include "game.h"

using namespace std;


Game::Game(int curLevel): curLevel{curLevel} {}

Game::~Game() {
    for (int i = 0; i < loBlocks.size(); i++)//free blocks
        delete loBlocks[i];
    delete gBoard;//free grid;
    delete queueBoard;//free sub grid
    if (graphicsON)//if it is a graphic display
    {
        delete gBoard;//free graphic display
        delete queueBoard;//free sub-graphic display
    }
    //delete gLevel;//free level
    delete interpreter;//free command-line interpreter
}


void Game::isGraphicsON() {
  graphicsON = false;
}

void Game::makeScriptfile(string file) {
  scriptfile = file; //set scriptfile as given file
}

void Game::makeLevel(int num){
  curLevel = num;
}


void Game::levelUp(){
  ++curLevel;
  gLevel->updateLevel(curLevel);
}

void Game::levelDown(){
  --curLevel;
  gLevel->updateLevel(curLevel);
}

void Game::restartGame() {
  delete gBoard;
  delete queueBoard;
  delete interpreter;

  if (graphicsON) {
//delete gGraphicsDisplay;
    delete gTextDisplay;
  }

  else {
    delete gTextDisplay;
  }

//  gGraphicsDisplay = NULL;
  gTextDisplay = NULL;
  loBlocks.clear();

  gLevel->resetScore();
  runGame();
}


void Game::runGame() {

  interpreter = new CmdInterp();

    if (curLevel == 0) {
      gLevel = new Level0(0, 0, curLevel);
    }
    else if (curLevel == 1) {
      gLevel = new Level1(0, 0, curLevel);
    }
    else if (curLevel == 2) {
      gLevel = new Level2(0, 0, curLevel);
    }
    else if (curLevel == 3) {
      gLevel = new Level3(0, 0, curLevel);
    }
    else if (curLevel == 4) {
      gLevel = new Level4(0, 0, curLevel);
    }


  //sets up the board
  gBoard = new Board(18,11);
  queueBoard = new Board(4,4);


    // set up coordinates
    Coordinate refPos;
    refPos.x = 0;
    refPos.y = 0;

    // generate new block based on level
    curBlock = gLevel->getNextBlock(gBoard, refPos);
    loBlocks.push_back(curBlock);

    //nextBlock = gLevel->getNextBlock(queueBoard, refPos);
    //loBlocks.push_back(nextBlock);


      if (graphicsON) {
        //if true, displays graphics
    //gGraphicsDisplay = new gDisplay(gBoard, queueBoard);
    //gGraphicsDisplay->initialize();
    //gGraphicsDisplay->drawBlankBoard();
    //curBlock->draw(gGraphicsDisplay, 0);
    //nextBlock->draw(gGraphicsDisplay, 1);

      }
      // displays both text and graphics
      //gGraphicsDisplay = NULL;
        gTextDisplay = new tDisplay(gBoard, queueBoard, gLevel);
        curBlock->initBoard(gBoard);
        cout << *gTextDisplay;

  while(true) {
    string command;


    // reads in commands to be preformed on the block
    while(cin >> command) {
      //extracts the multiplier from the command
      istringstream multiStr(command);
      int temp = 0; //temp to store the multiplier
      int multiNum = 0;
      string subCommand = command; //default to command, unless there is a multiplier
      if (multiStr >> temp) {
        multiNum = temp;
      }
      if (multiStr >> subCommand) {
      }

      if (interpreter->rightCmd(subCommand) == "right") {
        curBlock->goRight();
        cout << *gTextDisplay;
         --multiNum;
        while (multiNum > 0) {
          curBlock->goRight();
          cout << *gTextDisplay;
          --multiNum;
        }
      }

      else if (interpreter->leftCmd(subCommand) == "left") {
        curBlock->goLeft();
        cout << *gTextDisplay;
        --multiNum;
        while (multiNum > 0) {
          curBlock->goLeft();
          cout << *gTextDisplay;
          --multiNum;
        }
      }


      else if (interpreter->downCmd(subCommand) == "down") {
        cout << "down command" << endl;
        curBlock->goDown();
        cout << *gTextDisplay;
        --multiNum;
        while (multiNum > 0) {
          curBlock->goDown();
          cout << *gTextDisplay;
          --multiNum;
        }
      }

      else if (interpreter->CWCmd(subCommand) == "clockwise") {
        curBlock->rotate(0);
          cout << *gTextDisplay;
          --multiNum;
        while (multiNum > 0) {
          curBlock->rotate(0);
          cout << *gTextDisplay;
          --multiNum;
        }
      }

      else if (interpreter->CCWCmd(subCommand) == "counterclockwise") {
        curBlock->rotate(1);
          cout << *gTextDisplay;
          --multiNum;
        while (multiNum > 0) {
          curBlock->rotate(1);
          cout << *gTextDisplay;
          --multiNum;
        }
      }

      else if (interpreter->levelupCmd(subCommand) == "levelup") {
        levelUp();
          cout << *gTextDisplay;
          --multiNum;
        while(multiNum > 0) {
          levelUp();
          cout << *gTextDisplay;
          --multiNum;
        }
      }

      else if (interpreter->leveldownCmd(subCommand) == "leveldown") {
        levelDown();
          cout << *gTextDisplay;
          --multiNum;
        while(multiNum > 0) {
          levelDown();
          cout << *gTextDisplay;
          --multiNum;
        }
      }

      else if (interpreter->dropCmd(subCommand) == "drop") {
        cout << "drop command" << endl;
        curBlock->drop();
        gBoard->clearFullLines(*gLevel);
        curBlock = gLevel->getNextBlock(gBoard, refPos);
        loBlocks.push_back(curBlock);
        curBlock->initBoard(gBoard);
        cout << *gTextDisplay;
        --multiNum;
        /*while(multiNum > 0) {
          curBlock->drop();
          cout << *gTextDisplay;
          cout <<
          curBlock = gLevel->getNextBlock(gBoard, refPos);
          loBlocks.push_back(curBlock);
          --multiNum;
          if (multiNum > 0) {
            curBlock = nextBlock;
            nextBlock = gLevel->getNextBlock(queueBoard, refPos);
            loBlocks.push_back(nextBlock);
        }
        else break;
      } */
    }

      else if(interpreter->restartCmd(subCommand) == "restart") { //cannot apply multiplier
        gBoard->reset();
        restartGame();
        return;
      }

      else if(interpreter->hintCmd(subCommand) == "hint") { //cannot apply multiplier
        //TODO
      }

      else if(interpreter->norandomCmd(subCommand) == "norandom") { //cannot apply multiplier
        //TODO
      }

      else if (interpreter->norandomCmd(subCommand) == "random") { //cannot apply multiplier
        //TODO
      }
      else {
        if (cin.eof()) break;     //exit on ctrl+D
        cin.clear();              // clears the fail bit on cin
        cin.ignore();
      }
    }
    curBlock = nextBlock;
    nextBlock = gLevel->getNextBlock(queueBoard, refPos);
    loBlocks.push_back(nextBlock);
  }
}
