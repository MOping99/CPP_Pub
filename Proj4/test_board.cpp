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

	cout << "Current Board :\n" << Game;
	int count = 0;
	bool contain3 = true;

	while(contain3){
	vector<int> counts;

	for(int i = 0; i < Game.dimension(); i++){
		for(int j = 0; j < Game.dimension(); j++){
			if(Game.vcount(i, j) >= 3){
				count++;
				Game.shift(i, j);
				cout << "the board after shift " << count <<" :\n" << Game;
			}
		}
	}

	for(int i = 0; i < Game.dimension(); i++){
		for(int j = 0; j < Game.dimension(); j++){
			counts.push_back(Game.vcount(i, j));
		}

	contain3 = false;

	for(int i = 0; i < counts.size(); i++){
		if(counts[i] >= 3){
			contain3 = true;
		}
	}

  }

}

	cout << "total number of shifts : " << count << endl;



	return 0;

}
