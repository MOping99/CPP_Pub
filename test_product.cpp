// MCS 360 Project Two by <Mikael & Victor>

// P-2 MCS 360 due Fri 11 Oct 2019 : test_product.cpp

// Tests the methods defined by the class Product.

#include <iostream>
#include <iomanip>
#include "product.h"

using namespace std;

int main()
{
   Monomial cubic = Monomial("x", 3);
   Product prod = Product(cubic);

   cout << "A cubic : " << prod << endl;

   cout << "Give a monomial : ";
   Monomial yourm; cin >> yourm;
   cout << "Your monomial : " << yourm << endl;;

   prod = prod*yourm;

   cout << cubic << "*" << yourm << " : " << prod << endl;
   cout << "The number of monomials : " << prod.size() << endl;

   cout << "Give a number : ";
   double x; cin >> x;

   double y1 = cubic(x);
   double y2 = yourm(x);
   double z = prod(x);

   cout << scientific << setprecision(4);
   cout << cubic << " evaluated at " << x << " is "  << y1 << endl;
   cout << yourm << " evaluated at " << x << " is "  << y2 << endl;
   cout << prod << " evaluated at " << x << " is "  << z << endl;
   cout << y1 << "*" << y2 << " is " << y1*y2 << endl;

   cout << "Give a product of monomials : ";
   Product yourp; cin >> yourp;
   cout << "Your product : " << yourp << endl;

   cout << "(" << prod << ")*(" << yourp << ") is " << prod*yourp << endl;

   return 0;
}
