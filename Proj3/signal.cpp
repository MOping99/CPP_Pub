#include "signal.h"

Signal::Signal()//Constructs a signal object with state and elapsed at 0.
{state = 0;	elapsed = 0;}

int Signal::get_state()//Returns the value of private member state.
{return state;}

int Signal::get_elapsed()//Returns the value of private member elapsed.
{return elapsed;}

void Signal::next()//Iterates to the next state and elapsed time.
{
	state = state + 1;//Iterate state.
	elapsed = elapsed + 1;//Iterates elsapsed.
	
	if(state > 3)//Sets state to zero once it cycles through all the states.
		state = 0;
}

