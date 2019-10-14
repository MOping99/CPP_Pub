// MCS 360 Project Two by <Mikael & Victor>

//We require no other packages or headers since eveything is handled already
#include "monomial.h"

int main(){

//We only ever use 2 outside vaiables, a "x" double for calaulations and a
//"ours" monomial that was our input
  double x;
  Monomial ours;

//Our pre-defined self-set monomial for the code to run
  Monomial cubic = Monomial("x", 3);

//We output the information for the user
  cout << "A cubic : " << cubic << " \nits variable : " <<
  cubic.variable() << " and its power : " << cubic.power() << endl;

//We take in our number for calculations
  cout << "Give a number : ";
  cin >> x;

//We output the calaculated value we recived based on out monomial cubic
  cout << scientific << setprecision(4) << cubic <<
  " evaluated at " << x << " is "  << cubic(x) << endl;

//We take in an input of a monomial and then output it to show it was
//properly handled
  cout << "Give a monomial : ";
  cin >> ours;
  cout << "Your monomial : " << ours << endl;

//This next block of code is meant to compare our monomial with the pre-set one
//based on wether they are equal or not we tell the user the comparison of them
  if(cubic == ours){
     cout << "your monomial is equal to " << cubic << endl;
  }
  else{
     cout << "your monomial is not equal to " << cubic << endl;
     if(cubic < ours){
        cout << cubic << " < " << ours << endl;
     }
     else{
        cout << ours << " < " << cubic << endl;
     }
  }

//We then ouput the calcualted value based pn our monomial 
  cout << scientific << setprecision(4) << cubic <<
  " evaluated at " << x << " is "  << ours(x) << endl;

  return 0;
}
