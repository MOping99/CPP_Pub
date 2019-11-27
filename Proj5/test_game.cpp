// MCS 360 Project Three by Mikael Opingari and Daniel Zagal
//test_player.cpp

#include "player.cpp"

int main()
{
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

	Player Daniel = Player(&Game, "Daniel", 1);
	cout << Daniel;
	return 0;
}
