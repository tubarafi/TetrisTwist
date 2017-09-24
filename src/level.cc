#include "level.h"

using namespace std;

Level::Level(int currScore, int hiScore, int level): currScore{currScore}, hiScore{hiScore}, level{level}{}

Level::~Level() {}

int Level::getCurrScore() {
  return currScore;
}

int Level::getHiScore() {
  return hiScore;
}

void Level::resetScore() {
  currScore = 0;
}

void Level::updateHiScore() {
  if (currScore > hiScore) {
    hiScore = currScore;
  }
}

void Level::updateCurrScore(int points) {
  currScore = currScore + points;
}

int Level::getLevel() {
  return level;
}

void Level::updateLevel(int num) {
  level = num;
}
