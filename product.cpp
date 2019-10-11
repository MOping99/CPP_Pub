// MCS 360 Project Two by <Mikael & Victor>

#include "product.h"

int main(){

  Product prod1;
  Monomial x;
  Product prod2 = Product(x);
  Product prod3 = Product(prod2);

  list<Monomial> p = prod3.remember();

  cout << p.size();

  prod1.get_size(); prod2.get_size(); prod3.get_size();

  return 0;
}
