// MCS 360 Project Three by Mikael Opingari and Daniel Zagal

#ifndef SIGNAL_H
#define SIGNAL_H

class Signal{
	private:
		int arrivals;

	public:
		Lane(int time, int lambda);

    int size();

    void pop();

};

#endif
