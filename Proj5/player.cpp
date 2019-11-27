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
  score = 0;
}

int Player::get_level()
{return level;}

int Player::get_score()
{return score;}

void Player::play(){

  if(this -> get_level() == 0){
    //We define the integers that will be used to pick a coordinate
  	int rowind, colind;
  	//The state of play which we assume will always be true since there is no reason to run the program unless
  	//you wish to play with a corresponding string to we will use to check wether or no the user wishes to keep
  	//playing
  	bool play = true;
  	string yn;

  	while(play){
  		//We take in the users coordinate choice and use that as the first pass
  		cout << "-> give a row index : ";
  		cin >> rowind;
  		cout << "-> give a column index : ";
  		cin >> colind;

  		//We use this coordinate as the swap target and based on what we go of true or false we tell
  		//the player wether it scored or not
  		if(board -> swap(rowind, colind)){
  			score++;
  			cout << "The swap succeeded. Your score is " << score << endl;
  			cout << "Current Board :\n" << this -> board;
  		}
  		else{
  			cout << "The swap failed." << endl;
  			}


  		//We then do the destroying loop to add up all the times we remove a three or more chain, the only
  		//difference is, is that we count up everytime we remove a chain since that increases or score
  		//and every time we remove a chain we show the player the board
  		int count = 0;
  		bool contain3 = true;

  		while(contain3){

  			vector<int> buffer;

  			for(int i = 0; i < board -> dimension(); i++){
  				for(int j = 0; j < board -> dimension(); j++){
  					if(board -> vcount(i, j) >= 3 || board -> hcount(i, j) >= 3){
  						board -> shift(i, j);
  						//These 2 lines are the only substantial differences then the previous contain3 loop, it tracks the
  						//amount of swaps which are later added to the score and the other prints the board after a shift
  						count++;
  						cout << "the board after shift " << count <<" :\n" << this -> board;
  					}
  				}
  			}

  			for(int i = 0; i < board -> dimension(); i++){
  				for(int j = 0; j < board -> dimension(); j++){
  					buffer.push_back(board -> vcount(i, j));
  					buffer.push_back(board -> hcount(i, j));
  				}

  				contain3 = false;

  				for(int i = 0; i < buffer.size(); i++){
  					if(buffer[i] >= 3){
  						contain3 = true;
  					}
  				}

  			}

  		}

  	//This last section then asks the user wether or no they wish to play the game again and if the code recives
  	//a "y" we go over the loop again and ask for a new coordinate to check swap on
  	cout << "total number of shifts : " << count << endl;
  	score += count;
  	cout << "Your score " << name << " is " << score;
    play = false;
  }



}

}


ostream &operator<<(ostream &os, const Player &Obj)
{
	os << "Player " << Obj.name << " at level " << Obj.level << " has scored " << Obj.score << ".\n" << "The shared board is\n" << *(Obj.board);

	return os;
}
