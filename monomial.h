// MCS 360 Project Two by <Mikael & Victor>

#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

class Monomial{

  private:
    string symbol;
    int exponent;

  public:
    Monomial(){symbol = "x"; exponent = 1;};
    Monomial(string s, int e){symbol = s; exponent = e;};
    string variable(){return symbol;};
    int power(){return exponent;};

    bool operator==(const Monomial& rhs){
      if((this -> power()) == rhs.exponent)
        if((this -> variable()) == rhs.symbol)
          return true;
        else
          return false;
      else
        return false;
    };

    bool operator<(const Monomial& rhs){
    char l = tolower(this -> symbol[0]);
    char r = tolower(rhs.symbol[0]);
    if(l == r)
      return ((this -> exponent) < rhs.exponent);
    else
      return (l < r);;
    };

    print(){cout << symbol << "^" << exponent <<endl;};
};
