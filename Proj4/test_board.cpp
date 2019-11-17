// MCS 360 Project Three by Mikael Opingari and Daniel Zagal

//We import all our functions for the program
#include "board.cpp"


int main(){
	//We added this so that everyboard will always be different
	srand(time(NULL));

	//We initialize 2 variables that set how large our square board will be and how many different numbers
	//will be in the board, we then ask and recieve those numbers from the user before finally initalizing
	//the board we call game
	int dim, num;
	cout << "Give the dimension of the board : ";
	cin >> dim;
	cout << "Give the number of different items : ";
	cin >> num;
	Board Game = Board(dim, num);

	/*
	The while loops in our code are the most complicated sections in our code, with the later one being
	even more complex. This block is used to remove all chains from the starting board we have.
	*/

	//To being we make a booling called contain3 to say out code does contain a three or more long chain
	bool contain3 = true;
	while(contain3){

		//We then make a vector called buffer as a way to hold vcounts and hcounts for a coordinate we
		//define the vector in the loop as a way or re-setting it everytime we loop again
		vector<int> buffer;

		//We begin by looking at all coordinates and applying shift if a three does appear since we would
		//not want the player to start with a chain present this will remove any of these chains that
		//currently exist
		for(int i = 0; i < Game.dimension(); i++){
			for(int j = 0; j < Game.dimension(); j++){
				if(Game.vcount(i, j) >= 3  || Game.hcount(i, j) >= 3){
					Game.shift(i, j);
				}
			}
		}

		//This next section will loop through the board again and store in buffer all coordinates vcounts and hcounts
		//we store these to make sure we didn't accidentally make more chains while destroying the previous chains
		for(int i = 0; i < Game.dimension(); i++){
			for(int j = 0; j < Game.dimension(); j++){
				buffer.push_back(Game.vcount(i, j));
				buffer.push_back(Game.hcount(i, j));
			}

			//We then assume that the board does contain no three chains and assuming our loop checking the buffer does
			//not contain any 3s or larger numbers we mainting it being false otherwise we make it true and the program
			//loops again breaking all the three chains or larger before checking to make sure nothing remains, and this
			//will continue every time until no chains of 3 or larger exist
			contain3 = false;
			for(int i = 0; i < buffer.size(); i++){
				if(buffer[i] >= 3){
					contain3 = true;
				}
			}

		}

	}

	cout << "The board :" << Game;
	//After having printed out the board, we loop through the board twice once to print out a board consisting of hcounts
	cout << "The horizontal counts : " << endl;
	for(int i = 0; i < Game.dimension(); i++){
		for(int j = 0; j < Game.dimension(); j++){
			cout << Game.hcount(i, j) << " ";
		}
		cout << endl;
	}
	//and the other printing out the vcounts of the board
	cout << "The vertical counts : " << endl;
	for(int i = 0; i < Game.dimension(); i++){
		for(int j = 0; j < Game.dimension(); j++){
			cout << Game.vcount(i, j) << " ";
		}
		cout << endl;
	}


	/*
	This loop area is meant to play the game, it contains the copy of the above loop that "destroys" three or
	more chains however this time it will add to the score if it does remove a big chain, to begin with though
	we take in user input.
	*/

	//We define the integers that will be used to pick a coordinate
	int rowind, colind;
	//The state of play which we assume will always be true since there is no reason to run the program unless
	//you wish to play with a corresponding string to we will use to check wether or no the user wishes to keep
	//playing
	bool play = true;
	string yn;
	//This final variable is to tally up the users score for how well they did during the game
	int score = 0;

	while(play){
		//We take in the users coordinate choice and use that as the first pass
		cout << "-> give a row index : ";
		cin >> rowind;
		cout << "-> give a column index : ";
		cin >> colind;

		//We use this coordinate as the swap target and based on what we go of true or false we tell
		//the player wether it scored or not
		if(Game.swap(rowind, colind)){
			score++;
			cout << "The swap succeeded. Your score is " << score << endl;
			cout << "Current Board :\n" << Game;
		}
		else{
			cout << "The swap failed." << endl;
			}


		//We then do the destroying loop to add up all the times we remove a three or more chain, the only
		//difference is, is that we count up everytime we remove a chain since that increases or score
		//and every time we remove a chain we show the player the board
		int count = 0;
		contain3 = true;

		while(contain3){

			vector<int> buffer;

			for(int i = 0; i < Game.dimension(); i++){
				for(int j = 0; j < Game.dimension(); j++){
					if(Game.vcount(i, j) >= 3 || Game.hcount(i, j) >= 3){
						Game.shift(i, j);
						//These 2 lines are the only substantial differences then the previous contain3 loop, it tracks the
						//amount of swaps which are later added to the score and the other prints the board after a shift
						count++;
						cout << "the board after shift " << count <<" :\n" << Game;
					}
				}
			}

			for(int i = 0; i < Game.dimension(); i++){
				for(int j = 0; j < Game.dimension(); j++){
					buffer.push_back(Game.vcount(i, j));
					buffer.push_back(Game.hcount(i, j));
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
	cout << "Your score is " << score << ". Continue ? (y/n)";
	cin >> yn;
	if(yn == "y"){
		play = true;
	}
	else{
		play = false;
	}
}

return 0;
}
