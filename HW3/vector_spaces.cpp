#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>


using namespace std;

class PlanarVectors{

  private:
    vector<double> twodim;

  public:
    PlanarVectors(double x, double y){
      twodim.push_back(x);
      twodim.push_back(y);
    };

    double comp_length(){
      return sqrt(pow(twodim[0],2)+pow(twodim[1],2));
    };

    string stringme(){
      string first = to_string(twodim[0]);
      string second =  to_string(twodim[1]);
      string ans = "<" + first + ", " + second + ">";
      return ans;
    };

};

class SpatialVectors{

  private:
    vector<double> threedim;

  public:
    SpatialVectors(double x, double y, double z){
      threedim.push_back(x);
      threedim.push_back(y);
      threedim.push_back(z);
    };

    double comp_length(){
      return sqrt(pow(threedim[0],2)+pow(threedim[1],2)+pow(threedim[2],2));
    };

    string stringme(){
      string first = to_string(threedim[0]);
      string second =  to_string(threedim[1]);
      string third = to_string(threedim[2]);
      string ans = "<" + first + ", " + second + ", " + third + ">";
      return ans;
    };

};

int main(){
  PlanarVectors Plane = PlanarVectors(2.5, 2.5);
  cout << Plane.comp_length() << endl;
  cout << Plane.stringme() << endl;
  SpatialVectors Space = SpatialVectors(2.5, 2.5, 2.5);
  cout << Space.comp_length() << endl;
  cout << Space.stringme() << endl;

}
