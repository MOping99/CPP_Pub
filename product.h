// MCS 360 Project Two by <Mikael & Victor>

#include "monomial.h"
#include <list>

class Product{

  private:
    list<Monomial> prod;

  public:
    Product(){};
    Product(Monomial mono){prod.push_back(mono);};

    int get_size(){cout << prod.size();};

};
