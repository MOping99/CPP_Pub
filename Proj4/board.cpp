// MCS 360 Project Three by Mikael Opingari and Daniel Zagal
//board.cpp

#include "board.h"

Board::Board(int dimen, int n)//The class constructer for board, taking in a dimension integer to construct a square board and a range integer.
{
  number = n;//Stores 'n' to be used as the range during random number generation.

  cout << "Generating a " << dimen << "-by-" << dimen << " board with " << number <<  " different items ..." << endl;//Outputs a message for user.

  for(int i = 0; i < dimen; i++)//Iterates through equal to the 'dimen' value to create 1d vectors to be placed in the board 2d vector.
  {
    vector<int> temp;//Creates a temporary 1d vector.
    for(int j = 0; j < dimen; j++)//Iterates through equal to 'dimen' to fill the 'temp' vector with random values.
    {
      int tempint = rand() % n;//Creates and stores a random integer in range 'n'.
      temp.push_back(tempint);//Pushes back the new random integer into the temp.
    }
    board.push_back(temp);//Pushes back the 'temp' vector into 'board' to fill out a square 2d vector.
  }
}


int Board::dimension()//Returns the dimension of the board.
{return board.size();}

int Board::hcount(int row, int col)//Returns an integer equal to the number of values that are equal to and horizontally adjacent to the given position.
{
	int count = 1, val = board[row][col], n = 1;
	/*Creates and sets integer variables to store the value we are seaching for, the count of occurences
	of stored value, and an 'n' used to iterate in one of the directions.*/

	while(val == board[row][col] && col-n >= 0)//Continues until the next 'val' is not the same as the value in the given input, or reached the end of the column.
	{
		if(board[row][col-n] == val)//Adds to count if the the next number in the column equals the value 'val'.
		{
			count++;
		}
		val = board[row][col-n];//Sets 'val' equal to the current board value to be checked by the while loop.
		n++;//Adds to 'n' to iterate through the column leftward.
	}

	val = board[row][col];//Resets 'val'.
	n = 1;//Resets 'n'.

	while(val == board[row][col] && col+n < board.size())//Continues until the next 'val' is not the same as the value in the given input, or reached the end of the column.
	{
		if(board[row][col+n] == val)//Adds to count if the the next number in the column equals the value 'val'.
		{
			count++;
		}
		val = board[row][col+n];//Sets 'val' equal to the current board value to be checked by the while loop.
		n++;//Adds to 'n' to iterate through the column rightward.
	}

	return count;//Returns the 'count'.
}

int Board::vcount(int row, int col)//Returns an integer equal to the number of values that are equal to and vertically adjacent to the given position.
{
	int count = 1, val = board[row][col], n = 1;
	/*Creates and sets integer variables to store the value we are seaching for, the count of occurences
	of stored value, and an 'n' used to iterate in one of the directions.*/

	while(val == board[row][col] && row-n >= 0 )//Continues until the next 'val' is not the same as the value in the given input, or reached the end of the column.
	{
		if(board[row-n][col] == val)//Adds to count if the the next number in the column equals the value 'val'.
		{
			count++;
		}
		val = board[row-n][col];//Sets 'val' equal to the current board value to be checked by the while loop.
		n++;//Adds to 'n' to iterate through the column upward.
	}

	val = board[row][col];//Resets 'val'.
	n = 1;//Resets 'n'.

	while(val == board[row][col] && row+n < board.size())//Continues until the next 'val' is not the same as the value in the given input, or reached the end of the column.
	{
		if(board[row+n][col] == val)//Adds to count if the the next number in the column equals the value 'val'.
		{
			count++;
		}
		val = board[row+n][col];//Sets 'val' equal to the current board value to be checked by the while loop.
		n++;//Adds to 'n' to iterate through the column downward.
	}

	return count;//Returns the count.
}

void Board::shift(int row, int col)//Alters the board at and above the given position, replacing the numbers with randomly generated numbers.
{
  assert(number > 1 && "This means every time we shift the same numbers will always appear");//Asserts that the board isnt a 1x1 board when shift is used.

  if(this -> vcount(row, col) >= 3)//Checks if the board position matches 3.
  {
    for(int i = 0; i <= row; i++)//Iterates through row.
    {
      board[i][col] = rand() % number;//Regenerates a random number for the position.
    }
  }

  if(this -> hcount(row, col) >= 3)//Checks if the board position matches 3.
  {
    for(int j = 0; j <= col; j++)//Iterates through column.
    {
      board[row][j] = rand() % number;//Regenerates a random number for the position.
    }
  }
}

/*
This section is one of the most complex in the entire code. Since we need to look in all directions and compare
the results for each possiblity it leads to us having a massively nested if statment.
*/

//On input we we take a coordinate of the board and eventually output wether or not what we did was successful.
bool Board::swap(int i, int j){
  //We begin with assertions here to stop the player from from accessing non-existent information, the && you see is
  //used so that users are able to read the reasoning when the assertion fails.
  assert(i >= 0 && i <= this -> dimension() && "You're trying to swap an item that doesn't exist;");
  assert(j >= 0 && j <= this -> dimension() && "You're trying to swap an item that doesn't exist;");

  //We initalize an int variable called holder, which lets swap the values of based on the cardinal direction we check
  //without accidentally losing information
  int holder;

  //The directions we check go in the order of the project discription with: up, down, left, or right. As soon as one of
  //them is found to result in a minimum of a three in a row we make the swap permanent and return the fact that we succeeded.

  //Given we have a row above us,
  if(i-1 >= 0){
    //We store the value above us in holder then make the coordinate above us equal to the chosen one as well as making them
    //chosen one equal to the value in holder.
    holder = board[i-1][j];
    board[i-1][j] = board[i][j];
    board[i][j] = holder;
    //We instantly check all changed values row and column to see if we made a three or longer chain, if so we return true if not...
    if(this -> vcount(i, j) >= 3 || this -> vcount(i-1, j) >= 3 || this -> hcount(i, j) >= 3 || this -> hcount(i-1, j) >= 3){
      return true;
    }
    else{
      //We swap back the values if we don't have a chain and instantly go to look at if we can access the data from the row below
      board[i][j] = board[i-1][j];
      board[i-1][j] = holder;
      //Then given we have a row below us,
      if(i+1 <= this -> dimension()){
        //We store everything as before using the same holder variable
        holder = board[i+1][j];
        board[i+1][j] = board[i][j];
        board[i][j] = holder;
        //As before we check to see wether or not we make an adequate chain and either return true and holding the new variable
        //locations or...
        if(this -> vcount(i, j) >= 3 || this -> vcount(i+1, j) >= 3 || this -> hcount(i, j) >= 3 || this -> hcount(i+1, j) >= 3){
          return true;
        }
        else{
          //We swap back the variable and begin looking at the columns
          board[i][j] = board[i+1][j];
          board[i+1][j] = holder;
          if(j-1 >= 0){
            //Like before we swap looking to make sure there is space on the left then swap using holder
            holder = board[i][j-1];
            board[i][j-1] = board[i][j];
            board[i][j] = holder;
            //We do the check yet again for all possible chains and either return true holding where everything is or we...
            if(this -> vcount(i, j) >= 3 || this -> vcount(i, j-1) >= 3 || this -> hcount(i, j) >= 3 || this -> hcount(i, j-1) >= 3){
              return true;
            }
            else{
              //We sawp back and go in for the final check
              board[i][j] = board[i][j-1];
              board[i][j-1] = holder;
              if(j+1 <= this -> dimension()){
                //After checking to make sure we can go to the right we swap
                holder = board[i][j+1];
                board[i][j+1] = board[i][j];
                board[i][j] = holder;
                //The final check is made and we go to return true, if this one does not work all cardinal directions have been checked
                if(this -> vcount(i, j) >= 3 || this -> vcount(i, j+1) >= 3 || this -> hcount(i, j) >= 3 || this -> hcount(i, j+1) >= 3){
                  return true;
                }
                else{
                  //Since being here means we failed, we swap everything to where is should be and return to the the user a false boolean
                  //to show that we failed.
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

  //This is a catch-all return if something goes horribly wrong
  return false;
}

ostream &operator<<(ostream &os, const Board &Obj)//defines the friendly output overload to allow the board object to be printed in the form of a square board.
{
  for(int i = 0; i < Obj.board.size(); i++)//Loops through the rows of the vector.
  {
    for(int j = 0; j < Obj.board.size(); j++)//Loops through the columns of the vector.
    {
      os << Obj.board[i][j] << " ";//Outputs the integer at the current row i and column j followed by a space.
    }
    os << "\n";//Starts new line after all columns of a specific row is printed.
  }

  return os;//Returns os to be printed.
}
