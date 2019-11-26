// MCS 360 Project Three by Mikael Opingari and Daniel Zagal
//player.cpp

#include "player.h"
#include <cassert>

using namespace std;

Player::Player(Board* ptr_inBoard, string inName, int startLv = 0)
{
	board = ptr_inBoard;
	name = inName;
	level = startLv;
}

int Player::get_level()
{return level;}

int Player::get_score()
{return score;}

void Player::play()
{}

ostream &operator<<(ostream &os, const Player &Obj)
{
	os << "Player " << Obj.name << " at level " << Obj.level << " has scored " << Obj.score << ".\n" << "The shared board is\n" << *(Obj.board);
	
	return os;
}
