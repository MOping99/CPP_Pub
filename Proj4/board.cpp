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
  assert(number > 1 && "This means every time we shift the same numbers will always appear");
	for(int i = 0; i <= row; i++)
	{
	   board[i][col] = rand() % number;
	}
}

bool Board::swap(int i, int j)
{
  assert(i >= 0 && i <= this -> dimension() && "You're trying to swap an item that doesn't exist;");
  assert(j >= 0 && j <= this -> dimension() && "You're trying to swap an item that doesn't exist;");

  if(i-1 >= 0){
    int holder = board[i-1][j];
    board[i-1][j] = board[i][j];
    board[i][j] = holder;
    if(this -> vcount(i, j) >= 3 || this -> vcount(i-1, j) >= 3){
      return true;
    }
    else{
      board[i][j] = board[i-1][j];
      board[i-1][j] = holder;
      return false;
    }
  }

  //Repeate the above statment changing it for the other cardinat directions
  //in the checking if stament be sure to also look at the hcounts for the
  //everything. We also need to consider the shift function removing horizontal
  //3 or mores which mean editing the while loops.

  return false;
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
