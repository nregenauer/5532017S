//Nicole Regenauer
//HW2d: Choose(n,r)
//I pledge my honor that I have abided by the Stevens Honor System

#include <iostream>
#include <cmath>
using namespace std;

double factorial(unsigned int n){
  if(n==0 || n==1){
    return 1;
  }
  return n * factorial(n-1);
}

double choose(unsigned int n, unsigned int r){
  if(r>n){
    cout << "Invalid input" << endl;
    return -1;
  }
  return factorial(n)/(factorial(r)*factorial(n-r));

}

int main(){
  while(1){
  unsigned int a;
  unsigned int b;
  cout << "Input numbers: " << endl;
  cin >> a;
  cin >> b;
  cout << choose(a,b);
}
}
