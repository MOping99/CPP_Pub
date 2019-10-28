// MCS 360 Project Three by Mikael Opingari and Daniel Zagal

#ifndef LANE_H
#define LANE_H

#include <queue>

class Lane{
	private:
		queue<double> arrivals;
		
	public:
		Lane(int length, int lambda, bool verbose);
		
		int size();
		
		void pop();
	
};

#endif
