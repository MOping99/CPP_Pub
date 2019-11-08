// MCS 360 Project Three by Mikael Opingari and Daniel Zagal
//test_board.cpp

#include "board.cpp"


int main(){

	int dim, num;

	cout << "Give the dimension of the board : ";
	cin >> dim;
	cout << "Give the number of different items : ";
	cin >> num;


	Board Game = Board(dim, num);

	cout << "The board :" << endl;

	cout << Game;

	cout << "The horizontal counts : " << endl;
	for(int i = 0; i < Game.dimension(); i++){
		for(int j = 0; j < Game.dimension(); j++){
			cout << Game.hcount(i, j) << " ";
		}
		cout << endl;
	}

	cout << "The vertical counts : " << endl;
	for(int i = 0; i < Game.dimension(); i++){
		for(int j = 0; j < Game.dimension(); j++){
			cout << Game.vcount(i, j) << " ";
		}
		cout << endl;
	}
	//cout << Game.vcount(1, 4) << "\n\n";
	//Game.swap(3,1);
	//cout << Game << endl;

	return 0;

}
