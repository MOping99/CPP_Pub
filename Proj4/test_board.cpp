// MCS 360 Project Three by Mikael Opingari and Daniel Zagal
//test_board.cpp

#include "board.cpp"


int main(){
	Board Game = Board(6, 3);

	cout << Game << endl;
	cout << Game.dimension() << endl;
	cout << Game.hcount(3, 1) << endl;
	cout << Game.vcount(1, 4) << "\n\n";
	Game.swap(3,1);
	cout << Game << endl;

	return 0;
    
}
