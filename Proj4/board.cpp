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


int Board::dimension(){
  return board.size();
}

int Board::hcount(int row, int col){

	int count = 1, val = board[row][col], n = 1;

	while(val == board[row][col] && col-n >= 0){
		if(board[row][col-n] == val){
			count++;
		}
		val = board[row][col-n];
		n++;
	}

	val = board[row][col];
	n = 1;

	while(val == board[row][col]){
		if(board[row][col+n] == val && col+n < board.size()){
			count++;
		}
		val = board[row][col+n];
		n++;
	}

	return count;
}

int Board::vcount(int row, int col){

	int count = 1, val = board[row][col], n = 1;

	while(val == board[row][col] && row-n >= 0 ){
		if(board[row-n][col] == val){
			count++;
		}
		val = board[row-n][col];
		n++;
	}

	val = board[row][col];
	n = 1;

	while(val == board[row][col] && row+n < board.size()){
		if(board[row+n][col] == val){
			count++;
		}
		val = board[row+n][col];
		n++;
	}

	return count;
}

void Board::shift(int row, int col){

  assert(number > 1 && "This means every time we shift the same numbers will always appear");

  if(this -> vcount(row, col) >= 3){
    for(int i = 0; i <= row; i++){
	   board[i][col] = rand() % number;
	  }
  }

  if(this -> hcount(row, col) >= 3){
    for(int j = 0; j <= col; j++){
	   board[row][j] = rand() % number;
	  }
  }
}

bool Board::swap(int i, int j){
  assert(i >= 0 && i <= this -> dimension() && "You're trying to swap an item that doesn't exist;");
  assert(j >= 0 && j <= this -> dimension() && "You're trying to swap an item that doesn't exist;");

  int holder;

  if(i-1 >= 0){
    holder = board[i-1][j];
    board[i-1][j] = board[i][j];
    board[i][j] = holder;
    if(this -> vcount(i, j) >= 3 || this -> vcount(i-1, j) >= 3 || this -> hcount(i, j) >= 3 || this -> hcount(i-1, j) >= 3){
      return true;
    }
    else{
      board[i][j] = board[i-1][j];
      board[i-1][j] = holder;
      if(i+1 <= this -> dimension()){
        holder = board[i+1][j];
        board[i+1][j] = board[i][j];
        board[i][j] = holder;
        if(this -> vcount(i, j) >= 3 || this -> vcount(i+1, j) >= 3 || this -> hcount(i, j) >= 3 || this -> hcount(i+1, j) >= 3){
          return true;
        }
        else{
          board[i][j] = board[i+1][j];
          board[i+1][j] = holder;
          if(j-1 >= 0){
            holder = board[i][j-1];
            board[i][j-1] = board[i][j];
            board[i][j] = holder;
            if(this -> vcount(i, j) >= 3 || this -> vcount(i, j-1) >= 3 || this -> hcount(i, j) >= 3 || this -> hcount(i, j-1) >= 3){
              return true;
            }
            else{
              board[i][j] = board[i][j-1];
              board[i][j-1] = holder;
              if(j+1 <= this -> dimension()){
                holder = board[i][j+1];
                board[i][j+1] = board[i][j];
                board[i][j] = holder;
                if(this -> vcount(i, j) >= 3 || this -> vcount(i, j+1) >= 3 || this -> hcount(i, j) >= 3 || this -> hcount(i, j+1) >= 3){
                  return true;
                }
                else{
                  board[i][j] = board[i][j+1];
                  board[i][j+1] = holder;
                  return false;
                }
              }
            }
          }
        }
      }
    }
  }

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
