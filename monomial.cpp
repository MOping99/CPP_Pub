// MCS 360 Project Two by <Mikael & Victor>

#include "monomial.h"

int main(){

  Monomial x("l", 8);
  Monomial y("v", 5);

  x.print();
  y.print();

  bool b = (x<y);
  cout << b;

  return 0;
}
