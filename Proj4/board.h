// MCS 360 Project Three by Mikael Opingari and Daniel Zagal

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <stdlib.h>
#include <vector>


using namespace std;

class Board{

  private:
    int number;


  public:
    friend ostream &operator<<(ostream &os, const Monomial &Obj){
      os << Obj.symbol << "^" << Obj.exponent;
      return os;
    };

}

#endif
