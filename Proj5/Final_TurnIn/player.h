// MCS 360 Project Three by Mikael Opingari and Daniel Zagal
//player.h

#ifndef PLAYER_H
#define PLAYER_H

#include "board.cpp"//We use this to import all pervious functions and standard header files

class Player{

  private:
	string name; //Stores the players name
	Board* board; //Is used to make a board copy that all players can use
	int level, score; //level holds the level of play which will decide their strategy
  //score is used to rank players at the end based on their performance

  public:
	Player(Board*, string, int); //The constructor for our object it used to make a players
  //that all play with the same board as well as taking in their name and their strategy level

	int get_level(); //A function to return the strategy level of a player

	int get_score(); //A function to return the score of a player

	void play(); //The overarching function of the code and used to allow a player the ability to
  //send a turn

	friend ostream &operator<<(ostream &os, const Player &Obj); // A function that will output then
  //the board of a player along with who they are strategy and score
};

#endif
