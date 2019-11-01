#include "signal.cpp"
#include "lane.cpp"
#include <vector>
#include <windows.h>

int main(){

  int time;
  double lambda;
  bool verbose = false;

  cout << "Give us a positive integer : ";
  cin >> time;
  cout << "Give lambda : ";
  cin >> lambda;
  cout << "Generating the queues..." << endl;

  vector<Lane> Crossings;
  vector<double> Waits;

  for(int i = 0; i < 12; i++){

  Sleep(100);
  Lane test = Lane(time, lambda, verbose);

  Crossings.push_back(test);

  }

  cout << "Size of lanes : ";

  for(int i = 0; i < 12; i++){

    cout << Crossings[i].size() << " ";

  }

  cout << endl << "...." << endl;

  cout << "Average waiting times for each queue :" << endl;


  Signal states = Signal();
  int s, e;

  s = test.get_state();//Stores state.
  e = test.get_elapsed();//Stores elsaped.


  for(int i = 0; i < 12; i++){

    cout << "queue [" << i << "] : " << Waits[i]/Crossings[i].size() << endl;

  }

  return 0;
}
