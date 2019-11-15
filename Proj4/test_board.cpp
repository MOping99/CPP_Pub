// MCS 360 Project Three by Mikael Opingari and Daniel Zagal
//test_board.cpp

#include "board.cpp"


int main(){
	//srand(time(NULL));

	int dim, num;

	cout << "Give the dimension of the board : ";
	cin >> dim;
	cout << "Give the number of different items : ";
	cin >> num;


	Board Game = Board(dim, num);

	bool contain3 = true;

	while(contain3){
	vector<int> buffer;

	for(int i = 0; i < Game.dimension(); i++){
		for(int j = 0; j < Game.dimension(); j++){
			if(Game.vcount(i, j) >= 3  || Game.hcount(i, j) >= 3){
				Game.shift(i, j);
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

	int rowind, colind;
	bool play = true;
	int score = 0;
	string yn;

	while(play){

	cout << "-> give a row index : ";
	cin >> rowind;
	cout << "-> give a column index : ";
	cin >> colind;

	if(Game.swap(rowind, colind)){
		score++;
		cout << "The swap succeeded. Your score is " << score << endl;
		cout << "Current Board :\n" << Game;
	}
	else{
		cout << "The swap failed." << endl;
		}


	int count = 0;
	contain3 = true;

	while(contain3){
	vector<int> buffer;

	for(int i = 0; i < Game.dimension(); i++){
		for(int j = 0; j < Game.dimension(); j++){
			if(Game.vcount(i, j) >= 3 || Game.hcount(i, j) >= 3){
				count++;
				Game.shift(i, j);
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
