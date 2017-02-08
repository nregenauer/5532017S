/* Nicole Regenauer
HW2a: windchill
I pledge my honor that I have abided by the Stevens Honor System
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
  double windchill;
  for(double i=5;i<=60;i+=5){
    for(double j=40;j>=-45;j-=5){
      windchill = 35.74 + 0.6215*j-35.75*(pow(i,0.16))+0.4275*j*(pow(i,0.16));
      cout << setw(4) <<round(windchill);
    } cout << "\n";
  }
  return 0;
}
