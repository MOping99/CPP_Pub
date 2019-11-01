// MCS 360 Project Three by Mikael Opingari and Daniel Zagal

#ifndef LANE_H
#define LANE_H

#include <queue>//To use the queue data structure to store arrival times

class Lane{
	private:
		std::queue<double> arrivals;//Used to store arrival times.

	public:
		Lane(int time, int lambda, bool verbose);//Constructs a Lane object using time, lambda and verbose variables as inputs to generate arrival times.

		int size();//Returns the size of the private member arrivals.

		double pop(int start, int end, bool verbose);//Prints and removes the arrival times between the parameters start and end.

};

#endif
