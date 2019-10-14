// MCS 360 Project Two by <Mikael & Victor>

#include "monomial.h"
#include <list>
#include <iterator>

class Product{

  private:
    list<Monomial> prod;

  public:
    Product(){};
    Product(Monomial mono){};
    Product(Product pro){};

    int size(){};

    operatorMult(Monomial mono){};
    operatorMult(Product pro){};

    bool operator==(){};

    double operator()(double doub){};

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

    friend ostream &operator<<(ostream &os, const Product &Obj){

      for (Monomial m :: Obj){
        os << m.symbol << "^" << m.exponent << "*";
      }
      
      return os;
    };

    //list<Monomial> remember(){return prod;};

};
