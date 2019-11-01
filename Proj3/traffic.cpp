#include "signal.cpp" //We import signal and lane .cpp files so that all the functions work
#include "lane.cpp"
#include <vector> //We import vector so we can store all our lanes and some other variables we need
#include <windows.h> //We import windows.h so we can add a small wait time to diversify the lane size

int main(){

//We assign variables we will use later to calculate everything
  int time;
  double lambda;
//Verbose is set to false so that we aren't shown the lanes being assigned as they are made
  bool verbose = false;

//We take in the input from user to make our lanes
  cout << "Give us a positive integer : ";
  cin >> time;
  cout << "Give lambda : ";
  cin >> lambda;
  cout << "Generating the queues..." << endl;

//We assign 3 vectors to:
//Hold our lanes
//Hold the total wait times of each line
//Hold the average wait time for each lane
  vector<Lane> Crossings;
  vector<double> Waits;
  vector<double> AverageWait;

//This loops is used to make and assign all 12 lanes into the Crossings vector
  for(int i = 0; i < 12; i++){

  Sleep(100);
  Lane test = Lane(time, lambda, verbose);

  Crossings.push_back(test);

  }

//This line and upcoming loop to print for the user the amount of cars in each lane
  cout << "Size of lanes : ";

  for(int i = 0; i < 12; i++){

    cout << Crossings[i].size() << " ";

  }

  cout << endl << "...." << endl;

  cout << "Average waiting times for each queue :" << endl;

//We setup our signal and it's variables that we will use to show the user the lights at the crossing
  Signal lights = Signal();
  int s, e;

  s = lights.get_state();//Stores state.
  e = lights.get_elapsed();//Stores elapsed.

  int i = 0;

//Verbose becomes true so that we can show the user how the cars are popped
  verbose = true;

//This next block is the most complicated part of the traffic.cpp code
//however, each if statement blocks off repeatign code to that is based on
//how the project asks us to let each lane move
  while(e < 5){

//At the first state we tell the user what state we are in and how cars are allowed to move
    if(s == 0){
      cout << "State : " << s << "  ";//Outputs the state value.
  		cout << "elasped time : " << e << '\n';//Outputs the elasped value.
      cout << "green for left traffic from north and south, red for all others\n";

//Following the project description we begin to pop lanes 0 and 1
//We store the lane size first and then pop the lane storing how
//long we wait in the vector Waits before calculating the Average
//wait by the size and storing that as well
      for(i; i < 2; i++){
        int lanesize = Crossings[i].size();
        Waits.push_back(Crossings[i].pop(e, time, verbose));
        AverageWait.push_back(Waits[i]/lanesize);
      }
    }
//As mentioned earlier the code here repeats only the range of i is changed which
//represents a different set of lanes being popped and their information stored
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

//This loop is used to finally print out the Average wait times for each queue of cars
  for(int i = 0; i < 12; i++){

    cout << "queue [" << i << "] : " << AverageWait[i] << endl;

  }

  return 0;
}
