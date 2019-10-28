// MCS 360 Project Three by Mikael Opingari and Daniel Zagal

#ifndef SIGNAL_H
#define SIGNAL_H

#include <queue>

class Lane{
	private:
    queue<double> arrivals;

	public:
		Lane(int time, int lambda, bool verbose);

    int size();

    void pop(int start, int end, bool verbose);

};

#endif
