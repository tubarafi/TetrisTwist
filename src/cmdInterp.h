#ifndef _INTERP_H_
#define _INTERP_H_

#include <iostream>
#include <string>

class CmdInterp {

public:
   CmdInterp();
  ~CmdInterp();
  std::string rightCmd(std::string command); //checks and returns the 'right' command
  std::string leftCmd(std::string command);  //checks and returns the 'left' command
  std::string downCmd(std::string command); //checks and returns the 'down' command
  std::string dropCmd(std::string command); //checks and returns the 'drop' command
  std::string CWCmd(std::string command); //checks and returns the 'cw' command
  std::string CCWCmd(std::string command); //checks and returns the 'ccw' command
  std::string levelupCmd(std::string command); //checks and returns the 'levelup' command
  std::string leveldownCmd(std::string command); //checks and returns the 'leveldown' command
  std::string restartCmd(std::string command); //checks and returns the 'restart' command
  std::string hintCmd(std::string command); // //checks and returns the 'hint' command -- figure out how to implement this
  std::string norandomCmd(std::string command);
  std::string randomCmd(std::string command);
  std::string sequenceCmd(std::string command);


};

#endif
