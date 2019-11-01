// MCS 360 Project Three by Mikael Opingari and Daniel Zagal

#ifndef LANE_H
#define LANE_H

#include <queue>

class Lane{
	private:
    std::queue<double> arrivals;

	public:
		Lane(int time, int lambda, bool verbose);

    int size();

    double pop(int start, int end, bool verbose);

};

#endif
