// MCS 360 Project Three by Mikael Opingari and Daniel Zagal

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Board{

  private:
    int number;
    vector<vector<int>> board;

  public:

    Board(int n, int dimen);

    int dimension();

    int hcount(int index);

    int vcount(int index);

    void shift(int hin, int vin);

    bool swap(int i, int j);

    friend ostream &operator<<(ostream &os, const Board &Obj);

}

#endif
