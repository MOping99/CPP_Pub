// MCS 360 Project Two by <Mikael & Victor>

#include "monomial.h"
#include <list>
#include <iterator>

class Product{

  private:
    list<Monomial> prod;

  public:
    Product(){};
    Product(Monomial mono){prod.push_back(mono);};

    list<Monomial> remember(){return prod;};
    int get_size(){cout << prod.size();};

};
