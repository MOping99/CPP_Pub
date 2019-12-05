// MCS 360 Project Three by Mikael Opingari and Daniel Zagal
//board.h

#ifndef BOARD_H
#define BOARD_H

#include <iostream>//Used to overload the output function for a board object.
#include <stdlib.h>//Used to generate the integers in board.
#include <time.h>//Used to generate numbers randomly.
#include <vector>//Used to store integers in a 2d vector.
#include <assert.h>//Used to assert certain conditions within the definitions of class methods.

using namespace std;

class Board{

  private:
    int number;//Stores the range in which each integer of a board position can be in.
    vector< vector<int> > board;//Used to store the integer values of the board for the game.

  public:

    Board(int dimen, int n);//The class constructer for board, taking in a dimension integer to construct a square board and a range integer.

    int dimension();//Returns the dimension of the board.

    int hcount(int row, int col);//Returns an integer equal to the number of values that are equal to and horizontally adjacent to the given position.

    int vcount(int row, int col);//Returns an integer equal to the number of values that are equal to and vertically adjacent to the given position.

    void shift(int hin, int vin);//Alters the board at and above the given position, replacing the numbers with randomly generated numbers.

    bool swap(int i, int j);//Checks whether the given position can be swapped with its adjacent positions in order to match three numbers.

    friend ostream &operator<<(ostream &os, const Board &Obj);//Declares a friendly output overload to allow the board object to be printed in the form of a square board.
};

#endif
