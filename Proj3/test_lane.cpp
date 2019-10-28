// MCS 360 Project Three by Mikael Opingari and Daniel Zagal

#include "lane.cpp"//Imports the lane class and its methods.

int main(){

  int time;
  double lambda;
  bool verbose = true;

  cout << "Give us a positive integer : ";
  cin >> time;
  cout << "Give lambda : ";
  cin >> lambda;

  Lane test = Lane(time, lambda, verbose);
  test.pop(time, lambda, verbose);

}
