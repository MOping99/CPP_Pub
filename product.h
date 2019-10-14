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
    Product(Product pro){prod = pro.remember();};

    list<Monomial> remember(){return prod;};
    int size(){cout << prod.size();};

    Product operator*(const Product& lhs, const Monomial& rhs){
    	Product newProduct = Product(lhs);
    	this -> push_back(rhs);
      return newProduct;
    };


};
