// MCS 360 Project Two by <Mikael & Victor>

//These are all the packages we need to actually
//make a monomial class that works

#include <iostream>
#include <iomanip>
#include <cctype>
#include <math.h>

using namespace std;

class Monomial{

//These are the private varibales that are constitute a monomial
  private:
    string symbol;
    int exponent;

//The first two constructors all us to define a empty Monomial = x^1
//or make one based on our specifications
  public:
    Monomial(){symbol = "x"; exponent = 1;};
    Monomial(string s, int e){symbol = s; exponent = e;};

//We have these to be able to access the private data outside of the class
    string variable(){return symbol;};
    int power(){return exponent;};

//The operator== considers the left side(this) and the right side rhs
//in ourder to come up with it's conclusion
    bool operator==(const Monomial& rhs){

//Since they can only be equal if both the power and variable are equivalent
//we use a nested if statment to check and return true with every other else
//retulting in a false output
      if((this -> power()) == rhs.exponent)
        if((this -> variable()) == rhs.symbol)
          return true;
        else
          return false;
      else
        return false;
    };

//The operator< considers the left side(this) and the right side rhs
//in ourder to come up with it's conclusion
    bool operator<(const Monomial& rhs){

//We first turn take each monomials symobol and take the lowercase
//versions to see if we should be basing the conclusion off symobol
//or exponent and based on the first if stament return the answer based
//on the the higherarchy or importance for monomials
      char l = tolower(this -> symbol[0]);
      char r = tolower(rhs.symbol[0]);
      if(l == r)
        return ((this -> exponent) < rhs.exponent);
      else
        return (l < r);
    };

//A quick one line way, that based off the imput finds "X"^(our exponent)
    double operator()(double num){
      return (pow(num,(this -> exponent)));
    };


//The following overloaded fucntions require the use of friends to
//opperate properly as well as the inclusion of an input and output pointer


//The ourput is rather simple in that it simply calls and displays it's info
    friend ostream &operator<<(ostream &os, const Monomial &Obj){
      os << Obj.symbol << "^" << Obj.exponent;
      return os;
    };

//The input is rather difficult and for it we first assume our input
//is a string that we edit to fit our needs
    friend istream &operator>>(istream &input, Monomial &Obj){
      string s;
      input >> s;

//We check here first to make sure we recived an adequit input and if we did
//we take a substring based on the position of the "^" to fill our monomial
      if(s.find("^") != string::npos){
        Obj.symbol = s.substr(0, s.find("^"));
        Obj.exponent = stoi(s.substr(s.find("^")+1));
      }
//Otherwise we turn our fault input into the symbol and assign 1 as the
//exponent to avoid every operator() resulting in 1
      else{
        Obj.symbol = s;
        Obj.exponent = 1;
      }
      return input;
    };

};
