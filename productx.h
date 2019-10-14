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

    double operator(double doub){};

    //list<Monomial> remember(){return prod;};
    
};
