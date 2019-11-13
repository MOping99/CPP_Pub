// MCS 360 Project Three by Mikael Opingari and Daniel Zagal

#include "board.h"

Board::Board(int dimen, int n){

  number = n;

  cout << "Generating a " << dimen << "-by-" << dimen << " board with " << number <<  " different items ..." << endl;

  for(int i = 0; i < dimen; i++){
    vector<int> temp;
    for(int j = 0; j < dimen; j++){
      int tempint = rand() % n;
      temp.push_back(tempint);
    }
    board.push_back(temp);
  }
}


int Board::dimension()
{return board.size();}

int Board::hcount(int row, int col)
{
	int count = 1, val = board[row][col], n = 1;
	while(val == board[row][col] && col-n >= 0)
	{
		if(board[row][col-n] == val)
		{
			count++;
		}
		val = board[row][col-n];
		n++;
	}

	val = board[row][col];
	n = 1;
	while(val == board[row][col])
	{
		if(board[row][col+n] == val && col+n < board.size())
		{
			count++;
		}
		val = board[row][col+n];
		n++;
	}

	return count;
}

int Board::vcount(int row, int col)
{
	int count = 1, val = board[row][col], n = 1;
	while(val == board[row][col] && row-n >= 0 )
	{
		if(board[row-n][col] == val)
		{
			count++;
		}
		val = board[row-n][col];
		n++;
	}

	val = board[row][col];
	n = 1;
	while(val == board[row][col] && row+n < board.size())
	{
		if(board[row+n][col] == val)
		{
			count++;
		}
		val = board[row+n][col];
		n++;
	}

	return count;
}

void Board::shift(int row, int col)
{
	for(int i = 0; i <= row; i++)
	{
	   board[i][col] = rand() % number;
	}
}

bool Board::swap(int i, int j)
{
	bool canSwap = false;

	return canSwap;
}

ostream &operator<<(ostream &os, const Board &Obj){

      for(int i = 0; i < Obj.board.size(); i++){
        for(int j = 0; j < Obj.board.size(); j++){
          os << Obj.board[i][j] << " ";
        }
        os << "\n";
      }

      return os;

    }
