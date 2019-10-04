// MCS 360 Project Two by <Mikael & Victor>

#include "monomial.h"
#include <list>

class Product{

  private:
    list<Monomial> prod;

  public:
    Product(){list<Monomial> prod;};
    Product(Monomial mono){list<Monomial> prod = {mono};};
    Product(Product prod){
      list<Monomial> new_prod(prod);
      new_prod.sort();
    };
  
    int size(){return (this -> size())};
  
    //Unsure of how to do multiplication as of yet
  
};
