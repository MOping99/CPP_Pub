#ifndef SIGNAL_H
#define SIGNAL_H

class Signal{
	private:
		int state;//Ranges from 0-3, for a total of 4 states.
		int elapsed;//The amount of time that passes between states.
		
	public:
		Signal();//Constructs a signal object with state and elapsed at 0.
		
		int get_state();//Returns the value of private member state.
		
		int get_elapsed();//Returns the value of private member elapsed.
		
		void next();//Iterates to the next state and elapsed time.
	
};

#endif
