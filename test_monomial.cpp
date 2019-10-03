// MCS 360 Project Two by <Mikael & Victor>

// P-2 MCS 360 due Fri 11 Oct 2019 : test_monomial.cpp

// Tests the methods defined by the class Monomial.

#include <iostream>
#include <iomanip>
#include "monomial.h"

using namespace std;

int main()
{
   Monomial cubic = Monomial("x", 3);

   cout << "A cubic : " << cubic << endl;
   cout << "its variable : " << cubic.variable();
   cout << " and its power : " << cubic.power() << endl;

   cout << "Give a number : ";
   double x; cin >> x;

   double y = cubic(x);

   cout << scientific << setprecision(4);
   cout << cubic << " evaluated at " << x
        << " is "  << y << endl;

   Monomial yourm;

   cout << "Give a monomial : ";
   cin >> yourm;

   cout << "Your monomial : " << yourm << endl;;

   if(cubic == yourm)
      cout << "your monomial is equal to " << cubic << endl;
   else
   {
      cout << "your monomial is not equal to " << cubic << endl;
      if(cubic < yourm)
         cout << cubic << " < " << yourm << endl;
      else
         cout << yourm << " < " << cubic << endl;
   }

   double z = yourm(x);

   cout << yourm << " evaluated at " << x
        << " is "  << z << endl;

   return 0;
}
