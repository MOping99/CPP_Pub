// P-3 MCS 360 due Wed 30 Oct 2019 : poisson_arrivals.h

// This program models the generation of the arrival times,
// in a some time interval using the Poisson distribution for a given mean.
// We use the algorithm in the constructor of the Lane class
// in the traffic simulation.

#include <iostream>
#include <chrono>
#include <random>
#include <queue>

using namespace std;

int main()
{
   unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
   default_random_engine generator(seed);

   queue<double> arrivals;

   cout << "Give a positive integer : ";
   int nbr; cin >> nbr;

   cout << "Give lambda : ";
   double lambda; cin >> lambda;

   poisson_distribution<int> distribution(lambda);

   cout << "Computing arrival times ..." << endl;
   for(int i=0; i<nbr; ++i)
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
   cout << "arrivals in time interval [0, " << nbr << "] :" << endl;
   while(!arrivals.empty())
   {
      cout << "  " << arrivals.front() << endl;
      arrivals.pop();
   }
   return 0;
}
