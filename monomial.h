// MCS 360 Project Two by <Mikael & Victor>

#include <iostream> 
#include <iomanip>

using namespace std;

class Monomial{

  private:
    string symbol;
    int exponent;

  public:
    Monomial(){symbol = "x"; exponent = 1;};
    Monomial(string s, int e){symbol = s; exponent = e;};


    print(){cout << symbol << "^" << exponent <<endl;};
};
