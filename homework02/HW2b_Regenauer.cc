//Nicole Regenauer
// HW2b: primes
//I pledge my honor that I have abided by the Stevens Honor System

#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(unsigned long long p){
    if(p==1){
      return false;
    }
    if(p==2){
      return true;
    }
    if(p==3){
      return true;
    }
    if(p%2==0){
      return false;
    }
    for(unsigned long long i=3; i <= sqrt(p);i+=2){
      if(p%i==0){
        return false;
      }
    }
    return true;
}

int main(){
  unsigned long long n;
  while(1){
  cout << "Enter a number to check: " << endl;
  cin >> n;
  if(cin.fail()){
    cout << "Invalid input, program terminating\n";
    break;
  }
  if(isPrime(n)){
    cout << n << " is prime\n";
  }
  else{
    cout << n << " is not prime\n";
  }
}
return 0;
}
