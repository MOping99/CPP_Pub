// MCS 360 Project Three by Mikael Opingari and Daniel Zagal
//player.cpp

#include "player.h"
#include <utility> //Used to allow us access to pairs and their functions

Player::Player(Board* ptr_inBoard, string inName, int startLv = 0) // The class constructer for player, taking in they
//board we plan on distributing, the player name, and their level of strategy
{
	board = ptr_inBoard; //Used to make a copy of the board, indicated by the above points
	name = inName; //Stores the player name
	level = startLv; //Stores the level of strategy
  score = 0; //Stores the score in which all players begin with 0
}

int Player::get_level() //Function used to retrieve the level of strategy
{return level;}

int Player::get_score() //Function used to retrieve the score of a player
{return score;}





































//The most important function which actually lets a player have their turn
//It begins by first telling all present who is playing as shown by the cout
//then it breaks people apart based on what their strategy and plays through
//strategies logic
void Player::play(){
  cout << this -> name << " it's you turn!" << endl;

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
	  		rowind = rand() % board -> dimension();
				cout << rowind << endl;
	  		cout << "-> give a column index : ";
				colind = rand() % board -> dimension();
				cout << colind << endl;

	  		//We use this coordinate as the swap target and based on what we go of true or false we tell
	  		//the player wether it scored or not
	  		if(board -> swap(rowind, colind)){
	  			score++;
	  			cout << "The swap succeeded. Your score is " << score << endl;
	  			cout << "Current Board :\n" << *board;
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
	  						cout << "the board after shift " << count <<" :\n" << *board;
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
	  	cout << "Your score " << name << " is " << score << endl;
	    play = false;
	  }
  }

  if(this -> get_level() == -1){
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
  			cout << "Current Board :\n" << *board;
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
  						cout << "the board after shift " << count <<" :\n" << *board;
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
  	cout << "Your score " << name << " is " << score << endl;
    play = false;
  }



}

if(this -> get_level() == 1){
	bool breaking = false;
	int row, col;
	for(int i = 0; i < board -> dimension(); i++){
		for(int j = 0; j < board -> dimension(); j++){
			if(board -> swap(i,j)){
				breaking = true;
				row = i;
				col = j;
			}
			if(breaking){
				break;
			}
		}
		if(breaking){
			break;
		}
	}

	if(breaking){
		cout << "-> give a row index : " << row << endl;
		cout << "-> give a column index : " << col << endl;
			score++;
			cout << "The swap succeeded. Your score is " << score << endl;
			cout << "Current Board :\n" << *board;
	}
	else{
		cout << "The swap failed. This board contains no more possible chains!" << endl;
		assert(0 == 1);
	}



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
					cout << "the board after shift " << count <<" :\n" << *board;
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



	//This last section then asks the user wether or no they wish to play the game again and if the code recives
	//a "y" we go over the loop again and ask for a new coordinate to check swap on
	cout << "total number of shifts : " << count << endl;
	score += count;
	cout << "Your score " << name << " is " << score << endl;
	}




}

if(this -> get_level() == 2){

	pair<int,int> best (-1,-1);
	int bestchain = -1;

	for(int x = 0; x < board -> dimension(); x++){
		for(int y = 0; y < board -> dimension(); y++){
			Board copy = *board;

			if(copy.swap(x,y)){
				int hs = copy.hcount(x, y);
				int vs = copy.vcount(x, y);

				if(hs >= vs){
					if(hs >= bestchain){
						bestchain = hs;
						best.first = x;
						best.second = y;
					}
				}
				else{
					if(vs >= bestchain){
						bestchain = vs;
						best.first = x;
						best.second = y;
					}
				}
			}



		}
	}

	bool breaking = false;
	int row = best.first;
	int col = best.second;
	if(board -> swap(row, col)){
		breaking = true;
	}
	if(breaking){
		cout << "-> give a row index : " << row << endl;
		cout << "-> give a column index : " << col << endl;
			score++;
			cout << "The swap succeeded. Your score is " << score << endl;
			cout << "Current Board :\n" << *board;
	}
	else{
		cout << "The swap failed. This board contains no more possible chains!" << endl;
		assert(0 == 1);
	}



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
				cout << "the board after shift " << count <<" :\n" << *board;
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
cout << "Your score " << name << " is " << score << endl;
}

}






























// A function that will output then the board of a player along with who they are strategy and score
ostream &operator<<(ostream &os, const Player &Obj){

	os << "Player " << Obj.name << " at level " << Obj.level << " has scored "
	<< Obj.score << ".\n" << "The shared board is\n" << *(Obj.board);
	return os;
}
