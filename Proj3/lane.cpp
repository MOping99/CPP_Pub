// MCS 360 Project Three by Mikael Opingari and Daniel Zagal

//None of the verbose settings have been implemented

#include "lane.h"//Imports the prototype of Lane to define the constructor and function.
#include <iostream>//Used to output to the user.
#include <chrono>//Used to randomly generate the lane.
#include <random>//used to randomly generate the lane.

using namespace std;


Lane::Lane(int time, int lambda, bool verbose)//Constructs a Lane object using time, lambda and verbose variables as inputs to generate arrival times.
{
	//Used to randomly generate the arrival times for arrivals queue.
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	default_random_engine generator(seed);
	poisson_distribution<int> distribution(lambda);

	if(verbose == true)//Prints a message to user if verbose is true.
	{
		cout << "Computing arrival times ..." << endl;
	}
	
	for(int i=0; i<time; ++i)//Generates arrival times equal to time.
	{
		int rnd = distribution(generator);//Randomly generates number.
		
		if(verbose == true)//Prints the number of arrivals to the user if verbose is true.
		{
			cout << "at step " << i << ", number of arrivals : " << rnd << endl;
		}

		if(rnd > 0)
		{
			double stepsize = 1.0/(rnd+1);
			
			for(int k=0; k<rnd; k++)
			{
				if(verbose == true)//Prints to user if verbose is true.
				{
					cout << "-> pushing " << i+stepsize*(k+1) << endl;
				}
				arrivals.push(i+stepsize*(k+1));
			}
		}
	}
}

int Lane::size()//Returns the size of the private member arrivals.
{return arrivals.size();}

double Lane::pop(int start, int end, bool verbose)//Prints and removes the arrival times between the parameters start and end.
{
	double wait = 0;
	if(verbose == true)//Prints the start and end input to user if verbose is true.
	{
	cout << "Popping in time interval [" << start << ", " << end << "] :" << endl;
	}
	
	while(!arrivals.empty())//Continues until the arrivals queue is empty.
	{
		double incr = start - arrivals.front();
		
		if(incr > 0)
		{
			wait += incr;
		}
		else{
			wait += 0;
		}
		
		if(verbose == true)//Prints the arrival and wait if verbose is true.
		{
			cout << "-> examining the top arrival " << arrivals.front() << endl;
			cout << "  popping " << arrivals.front() << ", wait : " << wait << endl;
		}
		arrivals.pop();//Pops the arival time from the queue.
	}
	
	if(verbose == true)//Prints the sum of waiting times if verbose is true.
	{
		cout << "sum of waiting times : " << wait << endl;
	}

	return wait;
}
