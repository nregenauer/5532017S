//Nicole Regenauer
//HW2e: Functions
//I pledge my honor that I have abided by the Stevens Honor System

#include <iostream>
using namespace std;

double fact(unsigned int n){
  if(n==0 || n==1){
    return 1;
  }
  double count =1;
  for(double i=2;i<=n;i++){
    count*=i;
  }
  return count;
}

double fact2(unsigned int n){
  if(n==0 || n==1){
    return 1;
  }
  return n * fact2(n-1);
}

double fibo(unsigned int n){
  int count = 1;
  int prev = 1;
  int sum;
  for(double i=2;i<n;i++){
    sum = count + prev;
    prev=count;
    count=sum;
  }
  return count;
}

double fibo2(unsigned int n){
  if(n==1 || n==2){
    return 1;
  }
  return fibo(n-2) + fibo(n-1);
}
double choose(unsigned int n, unsigned int r){
  if(r>n){
    cout << "Invalid input" << endl;
    return -1;
  }
  return fact2(n)/(fact2(r)*fact2(n-r));

}

int main() {
  cout << fact(5) << ' ' << fact2(5) << '\n';
  cout << fact(15) << ' ' << fact2(15) << '\n';
  cout << fibo(5) << ' ' << fibo2(5) << '\n';
  cout << fibo(13) << ' ' << fibo2(13) << '\n';
  cout << choose(52,6) << '\n';
}
