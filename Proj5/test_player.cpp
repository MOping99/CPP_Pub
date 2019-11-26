// MCS 360 Project Three by Mikael Opingari and Daniel Zagal
//test_player.cpp

#include "player.cpp"

int main()
{
	Board board = Board(5,4);
	Player Daniel = Player(&board, "Daniel", 1);
	cout << Daniel;
	return 0;
}
