// MCS 360 Project Three by Mikael Opingari and Daniel Zagal
//test_player.cpp

#include "player.cpp"

int main()
{

  /*        Code to setup game of a dynamic size & randomizer
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
  */

	Board Game = Board(5,4);

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

  Player Player_1 = Player(&Game, "Player_1", -1);
	Player CPU_Failure = Player(&Game, "CPU_Failure", 0);
  Player CPU_First = Player(&Game, "CPU_First", 1);
  Player CPU_Genius = Player(&Game, "CPU_Genius", 2);

	cout << Player_1 << CPU_Failure << CPU_First << CPU_Genius;

  bool playing = true;
  string yn;

  while(playing){

	Player_1.play();
  CPU_Failure.play();
  CPU_First.play();
  CPU_Genius.play();

  cout << "Another round? ";
  cin >> yn;
  if(yn == "y"){
		playing = true;
	}
	else{
		playing = false;
	}

  }

  cout << "Final Tally!" << endl;
  cout << Player_1 << CPU_Failure << CPU_First << CPU_Genius;
	cout << "The Winner of our Game was..." << endl;

	int points = -1;

	vector< Player > Players{Player_1, CPU_Failure, CPU_First, CPU_Genius};

	for(int i = 0; i < Players.size(); i++){

		if(Players[i].get_score() > points){
			points = Players[i].get_score();
		}
	}

	for(int j = 0; j < Players.size(); j++){
		if(Players[j].get_score() == points){
			cout << Players[j];
			cout << "Winning with his score of " << points << " points!" << endl;
		}
	}


	return 0;
}
