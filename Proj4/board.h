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

    Board(int n, int dimen){

      int number = n;

      for(int i = 0; i < dimen; i++){
        vector<int> temp;
      for(int j = 0; j < dimen; j++){
        int tempint = rand() % n;
        temp.push_back(tempint);
        }
        board.push_back(temp);
      }


    };

    int dimension();

    int hcount(int index);

    int vcount(int index);

    void shift(int hin, int vin);

    bool swap(int i, int j);

    friend ostream &operator<<(ostream &os, const Board &Obj){

      for(int i = 0; i < Obj.number; i++){
        for(int j = 0; j < Obj.number; j++){
          os << Obj.board[i][j] << " ";
        }
        os << "\n";
      }

      return os;

    }
};

#endif
