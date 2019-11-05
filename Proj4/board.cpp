// MCS 360 Project Three by Mikael Opingari and Daniel Zagal

#include "board.h"

Board::Board(int n, int dimen){

      int number = n;
      int dim = dimen;

      for(int i = 0; i < dim; i++){
        vector<int> temp;
        for(int j = 0; j < dim; j++){
          int tempint = rand() % n;
          temp.push_back(tempint);
        }
        board.push_back(temp);
      }
}


int Board::dimension(){



}

int Board::hcount(int index){



}

int Board::vcount(int index){



}

void Board::shift(int hin, int vin){



}

bool Board::swap(int i, int j){



}
