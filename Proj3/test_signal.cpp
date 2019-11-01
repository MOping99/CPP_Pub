// MCS 360 Project Three by Mikael Opingari and Daniel Zagal

#include "signal.cpp"//Imports the signal class and its methods.
#include <cassert>//To Assert that choice remains as 'y' or 'n'
#include <iostream>//Used to output to the user.

using namespace std;

int main()
{
	Signal test = Signal();//Creates a signal object called test.
	char choice = 'y';//To take in the y/n input of the user.
	int s, e;//To store the state and elasped value of the object test.

	while(choice == 'y')//Continues as long as choice is 'y'.
	{
		s = test.get_state();//Stores state.
		e = test.get_elapsed();//Stores elsaped.

		cout << "State : " << s << "  ";//Outputs the state value.
		cout << "elasped time : " << e << '\n';//Outputs the elasped value.

		if(s == 0)//Outputs appropriate message depending on state value.
			cout << "green for left traffic from north and south, red for all others\n";
		else if(s == 1)
			cout << "green for straight and right going traffic from north and south,\nred for all others\n";
		else if(s == 2)
			cout << "green for left traffic from west and east, red for all others\n";
		else
			cout << "green for straight and right going traffic from west and east,\nred for all others\n";

		cout << "Move to the next state ? (y/n) ";//Ask users for a y/n input.
		cin >> choice;//Takes in a y/n input.
		assert(choice == 'y' || choice == 'n');//Asserts that choice must be either 'y' or 'n'.

		if(choice == 'y')//Uses 'next' method if  choice is 'y'.
			test.next();//Goes to next state and interates elapsed.
	}

	return 0;
}
