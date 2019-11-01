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
  vector<double> AverageWait;

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


  Signal lights = Signal();
  int s, e;

  s = lights.get_state();//Stores state.
  e = lights.get_elapsed();//Stores elapsed.

  int i = 0;

  verbose = true;

  while(e < 5){

    if(s == 0){
      cout << "State : " << s << "  ";//Outputs the state value.
  		cout << "elasped time : " << e << '\n';//Outputs the elasped value.
      cout << "green for left traffic from north and south, red for all others\n";

      for(i; i < 2; i++){
        int lanesize = Crossings[i].size();
        Waits.push_back(Crossings[i].pop(e, time, verbose));
        AverageWait.push_back(Waits[i]/lanesize);
      }
    }
    if(s == 1){
      cout << "State : " << s << "  ";//Outputs the state value.
  		cout << "elasped time : " << e << '\n';//Outputs the elasped value.
      cout << "green for straight and right going traffic from north and south,\nred for all others\n";

      for(i; i < 6; i++){
        int lanesize = Crossings[i].size();
        Waits.push_back(Crossings[i].pop(e, time, verbose));
        AverageWait.push_back(Waits[i]/lanesize);
      }
    }
    if(s == 2){
      cout << "State : " << s << "  ";//Outputs the state value.
  		cout << "elasped time : " << e << '\n';//Outputs the elasped value.
      cout << "green for left traffic from west and east, red for all others\n";

      for(i; i < 8; i++){
        int lanesize = Crossings[i].size();
        Waits.push_back(Crossings[i].pop(e, time, verbose));
        AverageWait.push_back(Waits[i]/lanesize);
      }
    }
    if(s == 3){
      cout << "State : " << s << "  ";//Outputs the state value.
  		cout << "elasped time : " << e << '\n';//Outputs the elasped value.
      cout << "green for straight and right going traffic from west and east,\nred for all others\n";

      for(i; i < 12; i++){
        int lanesize = Crossings[i].size();
        Waits.push_back(Crossings[i].pop(e, time, verbose));
        AverageWait.push_back(Waits[i]/lanesize);
      }
    }

    lights.next();
    s = lights.get_state();//Stores state.
    e = lights.get_elapsed();//Stores elapsed.
  }


  for(int i = 0; i < 12; i++){

    cout << "queue [" << i << "] : " << AverageWait[i] << endl;

  }

  return 0;
}
