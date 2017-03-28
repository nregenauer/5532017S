#include <iostream>
using namespace std;

class DivByZero{
  //nothing in here so right now this is just a one byte object!
}

class Complex {
private:
  double r, i;
public:
  Complex(double r, double i) : r(r), i(i) {};
  //this is right on the edge where it would be faster to
  //use originals rather than make a copy
  //would just pas Complex& a, Complex& b
  friend Complex operator +(Complex a, Complex b){
      return Complex(a.r+b.r,a.i+b.i);
  }
  friend Complex operator -(Complex a, Complex b){
      return Complex(a.r-b.r,a.i-b.i);
  }
  friend Complex operator *(Complex a, Complex b){
    return Complex(a.r*b.r-a.i*b.i, a.r*b.i+a.i*b.r);
  }
  friend Complex operator /(Complex a, Complex b){
    if(b.r == 0 && b.i ==0)
      throw DivByZero();
    double magsq = b.r*b.r + b.i*b.i;
    return Complex((a.r*b.r+a.i*b.i)/magsq, (a.i*b.r-a.r*b.i)/magsq);
  }
};

int main(){
  Complex c1(1.0, 2.0);
  Complex c2(0.0,0.0);
  Complex c3=c1/c2;
}
