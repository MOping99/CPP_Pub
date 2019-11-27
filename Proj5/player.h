// MCS 360 Project Three by Mikael Opingari and Daniel Zagal
//player.h

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "board.cpp"

class Player{

  private:
	string name;
	Board* board;
	int level;
  int score = 0;

  public:
	Player(Board*, string, int);

	int get_level();

	int get_score();

	void play();

	friend ostream &operator<<(ostream &os, const Player &Obj);
};

#endif
