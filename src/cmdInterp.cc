#include "cmdInterp.h"
#include <string>

using namespace std;

CmdInterp::CmdInterp(){};

CmdInterp::~CmdInterp(){}

string CmdInterp::rightCmd(string command) {
  int len = command.length();
  string strBeg = command.substr(0,2);
  if (len >= 2 && len <= 5 && strBeg == "ri") {
    return "right";
  }
  else {
    return command;
  }
}

string CmdInterp::leftCmd(string command) {
  int len = command.length();
  string strBeg = command.substr(0,2);
  if (len >= 2 && len <= 5 && strBeg == "le") {
    return "left";
  }
  else {
    return command;
  }
}

string CmdInterp::downCmd(string command) {
  int len = command.length();
  string strBeg = command.substr(0,2);
  if (len >= 2 && len <= 4 && strBeg == "do") {
    return "down";
  }
  else {
    return command;
  }
}

string CmdInterp::dropCmd(string command) {
  int len = command.length();
  string strBeg = command.substr(0,2);
  if (len >= 2 && len <= 4 && strBeg == "dr") {
    return "drop";
  }
  else {
    return command;
  }
}

string CmdInterp::CWCmd(string command) {
  int len = command.length();
  string strBeg = command.substr(0,2);
  if (len >= 2 && len <= 16 && strBeg == "co") {
    return "counterclockwise";
  }
  else {
    return command;
  }
}

string CmdInterp::CCWCmd(string command) {
  int len = command.length();
  string strBeg = command.substr(0,2);
  if (len >= 2 && len <= 9 && strBeg == "cl") {
    return "clockwise";
  }
  else {
    return command;
  }
}

string CmdInterp::levelupCmd(string command) {
  int len = command.length();
  string strBeg = command.substr(0,6);
  if (len >= 6 && len <= 7 && strBeg == "levelu") {
    return "levelup";
  }
  else {
    return command;
  }
}

string CmdInterp::leveldownCmd(string command) {
  int len = command.length();
  string strBeg = command.substr(0,6);
  if (len >= 6 && len <= 9 && strBeg == "leveld") {
    return "leveldown";
  }
  else {
    return command;
  }
}

string CmdInterp::restartCmd(string command) {
  int len = command.length();
  string strBeg = command.substr(0,2);
  if (len >= 2 && len <= 7 && strBeg == "re") {
    return "restart";
  }
  else {
    return command;
  }
}

string CmdInterp::hintCmd(string command) {
  int len = command.length();
  string strBeg = command.substr(0,1);
  if (len >= 1 && len <= 7 && strBeg == "h") {
    return "hint";
  }
  else {
    return command;
  }
}

string CmdInterp::norandomCmd(string command) {
  int len = command.length();
  string strBeg = command.substr(0,1);
  if (len >= 1 && len <= 8 && strBeg == "n") {
    return "norandom";
  }
  else {
    return command;
  }
}

string CmdInterp::randomCmd(string command) {
  int len = command.length();
  string strBeg = command.substr(0,2);
  if(len >= 2 && len <= 6 && strBeg == "ra") {
    return "random";
  }
  else {
    return command;
  }
}

string CmdInterp::sequenceCmd(string command) {
  int len = command.length();
  string strBeg = command.substr(0,1);
  if(len >= 2 && len <= 6 && strBeg == "s") {
    return "sequence";
  }
  else {
    return command;
  }
}
