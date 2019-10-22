#include <iostream>
#include <vector>
#include <math.h>

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

    string to_string(){
      string ans = "<" + string(twodim[0]) + ", " string(twodim[1]) + ">";
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

};

int main(){
  PlanarVectors Plane = PlanarVectors(2.5, 2.5);
  cout << Plane.comp_length() << endl;
  cout << Plane.to_string() << endl;
  SpatialVectors Space = SpatialVectors(2.5, 2.5, 2.5);
  cout << Space.comp_length() << endl;
}
