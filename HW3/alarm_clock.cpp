#include <iostream>
#include "assert.h"

using namespace std;

class alarm_clock{

private:
  int hour;
  int minute;
  int second;

public:
  alarm_clock(int H, int M, int S){
    assert(H < 24 && H >= 0);
    assert(M < 60 && M >= 0);
    assert(S < 60 && S >= 0);
    hour = H;
    minute = M;
    second = S;
  };

  get_time(){
    cout << "The Clock's Time is "<<hour << ":" << minute << ":" << second << endl;
  };

};

int main(){

  alarm_clock WorkingClock = alarm_clock(21,59,10);
  WorkingClock.get_time();
  alarm_clock BrokenClock = alarm_clock(12,74,20);
  BrokenClock.get_time();

}
