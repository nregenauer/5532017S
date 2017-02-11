//Nicole Regenauer
//Hw3c: Robot Location Estimator
//I pledge my honor that I have abided by the Steven's Honor System


#include <iostream>
#include <cmath>
using namespace std;

int main(){

  double angle, distance;
  double x=0, y = 0;
  double pi = atan(1.0)*4;
  while(1){
    cout << "Enter an angle in degrees \n";
    cin >> angle;
    cout << "Enter a distance \n";
    cin >> distance;
    if(angle < 0 || distance < 0){
      cout << "Program terminating" << endl;
      break;
    }

    x += distance * sin(angle*pi/180);
    if (abs(x) < 0.000001){
      x=0.0;
    }
    y += distance * cos(angle*pi/180);
    if (abs(y) < 0.000001){
      y=0.0;
    }

    cout << "Current x value is: " << x << " and current y value is: "<< y << endl;

  }
}
