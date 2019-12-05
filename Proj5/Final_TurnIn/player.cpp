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

	//Level -1 is the strategy that implies human control, the logic for level -1 is essentialy the
	//test_game.cpp only with the option for multiple rounds removed from the player
	if(this -> get_level() == -1){
		//We define the integers that will be used to pick a coordinate
		int rowind, colind;

		//We take in the users coordinate choice and use that to see if they can make a chain
		cout << "-> give a row index : ";
		cin >> rowind;
		cout << "-> give a column index : ";
		cin >> colind;

		//If a chain has been created we give the user a point and tell them that it succeeded and then show
		//the new altered board to them, before we've removed the chain
		if(board -> swap(rowind, colind)){
			score++;
			cout << "The swap succeeded. Your score is " << score << endl;
			cout << "Current Board :\n" << *board;
		}
		//Or we tell them that they failed to make a chain making move on to the chain destruction at the
		//end of the function
		else{
			cout << "The swap failed." << endl;
		}

}

  if(this -> get_level() == 0){
	    //We define the integers that will be used to pick a coordinate
	  	int rowind, colind;

			//We make the output look like that of a real person however instead of actually taking in an input
			//we use rand() based on the dimensions of the board to pick the coordinates
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

  }

	if(this -> get_level() == 1){
		//Like before we define the integers that will be used to pick a coordinate however we also add
		//a boolean breaking, to notify us that we found a chain and wish to stop looking through the board
		bool breaking = false;
		int row, col;

		//As we loop through th board we contantly check to see wether a swap can be made, since swap returns
		//a boolean we use its return as a trigger to make breaking true as well as stroing the coordinate it
		//occured at
		for(int i = 0; i < board -> dimension(); i++){
			for(int j = 0; j < board -> dimension(); j++){
				if(board -> swap(i,j)){
					breaking = true;
					row = i;
					col = j;
				}
				//As breaking is set to true it triggers a break twice so that the nested for loop is existed
				if(breaking){
					break;
				}
			}
			if(breaking){
				break;
			}
		}

		//Since it's not nessecarily true we can loop through the board and find possible chain, we use breaking
		//being true to print out that a swap was made and showing it to the user
		if(breaking){
			cout << "-> give a row index : " << row << endl;
			cout << "-> give a column index : " << col << endl;
			score++;
			cout << "The swap succeeded. Your score is " << score << endl;
			cout << "Current Board :\n" << *board;
		}
		//And the opposite as a way to tell them their are no chains, and forcing the program to end by asserting
		//a clearly false statment
		else{
			cout << "The swap failed. This board contains no more possible chains!" << endl;
			assert(0 == 1);
		}

}

	if(this -> get_level() == 2){

		//We use pairs here for the first time as both a way to store our coordinates and gain
		//some experience with it, we also have an integer called bestchain which is clearly
		//impossible, the same way our coordinate is, as a way to compare it to any future values
		//and then alsways pick those future values
		pair<int,int> best (-1,-1);
		int bestchain = -1;

		//This loop goes through the base board all players share, however instead of opperating
		//on it, we make a complete non-pointer copy that we will effect everytime
		for(int i = 0; i < board -> dimension(); i++){
			for(int j = 0; j < board -> dimension(); j++){
				Board copy = *board;

				//Since swap can disfigure a board by making a chain, and his no way to unmake that chain
				//we swap on out copy and store the resulting chains length in both the horizontl axis as
				//well as the vertical axis
				if(copy.swap(i,j)){
					int hs = copy.hcount(i, j);
					int vs = copy.vcount(i, j);

					//The next thing we do is  a series of nested if statments to know if this coordinate is
					//the best in making a long chain. SInce the coordinate and the chain size is strored
					//outside the loop, we are immune from accidentally deleting them as we loops

					//The first if check to see if we should be making a horizantal or chain or a vertial one
					if(hs >= vs){
						//Given we need to make a horizantal chain, we see wether or not it's bigger then the best
						//chain if it is bigger not only do we store it as the best possible chain but also store
						//the coordinate that we found it in
						if(hs >= bestchain){
							bestchain = hs;
							best.first = i;
							best.second = j;
						}
					}
					else{
						//Given we need to make a vertical chain, we see wether or not it's bigger then the best
						//chain if it is bigger not only do we store it as the best possible chain but also store
						//the coordinate that we found it in
						if(vs >= bestchain){
							bestchain = vs;
							best.first = i;
							best.second = j;
						}
					}
				}

			}
		}

		//We then move the stored variable of the pair into a row and column variable aptly named row and
		//col and proceed to show the user his board and score changing. The reason we don't every check
		//to make sure if it did find a chain, is because if no chains where made, row and col are both -1
		//and fail a previous assertion the board has
		int row = best.first;
		int col = best.second;

		board -> swap(row, col);
		cout << "-> give a row index : " << row << endl;
		cout << "-> give a column index : " << col << endl;
		score++;
		cout << "The swap succeeded. Your score is " << score << endl;
		cout << "Current Board :\n" << *board;

}


	//As we did in the previous code for test_board.cpp and as we do in test_game.cpp, we loop through the
	//board removing all chains that currently exist in it. We do this so that the player next round has no
	//unfair advantages and also because these are the current players points

	//To do this we have a count variable which gets added to when a chain is destroyed, this destruction is
	//only occurs at chains the resulted from play and is why shift() is called. We also have a boolean called
	//contain3 which is true since swap is true.
	int count = 0;
	bool contain3 = true;

	while(contain3){

		//The "buffer" vector holds all of the hcounts and vounts we have when running through the loop ran
		//be reset every time we loop so that we aren't stuck in an infinte loop
		vector<int> buffer;

		//This first set of nested for loops is meant to destroy all the current chains on the board
		//although there should be only one chain currently when we remove it, we have the possiblity
		//of having created more chains
		for(int i = 0; i < board -> dimension(); i++){
			for(int j = 0; j < board -> dimension(); j++){
				if(board -> vcount(i, j) >= 3 || board -> hcount(i, j) >= 3){
					board -> shift(i, j);
					//The following two lines of code are then used to show the player the board after they have removed
					//a chain as well as increment the count which will later be added to the score.
					count++;
					cout << "the board after shift " << count <<" :\n" << *board;
				}
			}
		}

		//As stated before, since we can't be sure wether or not we've created more chains we loop thorough again
		//and add all the hcounts and vcounts
		for(int i = 0; i < board -> dimension(); i++){
			for(int j = 0; j < board -> dimension(); j++){
				buffer.push_back(board -> vcount(i, j));
				buffer.push_back(board -> hcount(i, j));
			}
		}

		//For the loop to end we need there to be no number three or larger in our buffer vector but rather then
		//trying to prove it is false, we make the contain3 boolean false automatically, and then try proving
		//it should be true
		contain3 = false;

		//This loop is meant to prove wether or not it does in fact contain 3 and if it does, we run the loop again
		//till we get false
		for(int i = 0; i < buffer.size(); i++){
			if(buffer[i] >= 3){
				contain3 = true;
			}
		}

	}

	//After all the removal of all chains we finally add the count of chains destroyed to their score and print it out
	//along with their total number of shifts. It's important to remember this score variable is carried over every round
	//so that no information is lost
	cout << "total number of shifts : " << count << endl;
	score += count;
	cout << "Your score " << name << " is " << score << endl;

}

// A function that will output then the board of a player along with who they are strategy and score
ostream &operator<<(ostream &os, const Player &Obj){

	os << "Player " << Obj.name << " at level " << Obj.level << " has scored "
	<< Obj.score << ".\n" << "The shared board is\n" << *(Obj.board);
	return os;
}
