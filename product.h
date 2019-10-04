// MCS 360 Project Two by <Mikael & Victor>

#include "monomial.h"
#include <list>

class Product{

  private:
    list<Monomial> prod;

  public:
    Product(){list<Monomial> prod;};

    //Stuck on creating a Product of 1
    //monomial and getting the size

    Product(Monomial mono){cout << mono;list<Monomial> prod = {mono};};

    int size(){return prod.size();};

    //Stuck on creating a Product of 1
    //monomial and getting the size

};
