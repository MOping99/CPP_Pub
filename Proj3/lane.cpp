// MCS 360 Project Three by Mikael Opingari and Daniel Zagal

//None of the verbose settings have been implemented

#include "lane.h"
#include <iostream>//Used to output to the user.
#include <chrono>
#include <random>

using namespace std;


Lane::Lane(int time, int lambda, bool verbose){
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  default_random_engine generator(seed);
  poisson_distribution<int> distribution(lambda);

  cout << "Computing arrival times ..." << endl;
  for(int i=0; i<time; ++i)
  {
     int rnd = distribution(generator);
     cout << "at step " << i << ", number of arrivals : " << rnd << endl;

     if(rnd > 0)
     {
        double stepsize = 1.0/(rnd+1);
        for(int k=0; k<rnd; k++)
        {
           cout << "-> pushing " << i+stepsize*(k+1) << endl;
           arrivals.push(i+stepsize*(k+1));
        }
     }
  }
}

int Lane::size(){
  return arrivals.size();

}

void Lane::pop(int start, int end, bool verbose){
  double wait = 0;
  cout << "Popping in time interval [" << start << ", " << end << "] :" << endl;
  while(!arrivals.empty())
  {
     cout << "-> examining the top arrival " << arrivals.front() << endl;
     cout << "  popping " << arrivals.front() << ", wait : " << wait << endl;
     arrivals.pop();
  }

}
