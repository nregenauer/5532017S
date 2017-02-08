//Nicole Regenauer
//HW2c: Multiple primes
//I pledge my honor that I have abided by the Stevens Honor System

#include <iostream>
#include <stdio.h>
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
    for(unsigned long long i=3; i<= sqrt(p);i+=2){
      if(p%i==0){
        return false;
      }
    }
    return true;
}

int countPrimes(unsigned long long a, unsigned long long b){
  unsigned long long counter = 0;
  if(a>b){
    cout << "Invalid range, program terminating" << endl;
    return -1;
  }
  for(unsigned long long i = a; i <= b; i++){
    if(isPrime(i)){
      counter++;
    }
  }
  return counter;

}

int main(){
  unsigned long long a=0;
  unsigned long long b=0;
  while(1){
  cout << "Enter two numbers" << endl;

  cin >> a;
  cin >> b;
  if (cin.fail()){
    cout << "Invalid input, program terminating" << endl;
    break;
  }

  cout << "There are " << countPrimes(a,b) << " prime numbers between " << a << " and " << b << endl;
  //cout << b;
}
  return 0;

}
