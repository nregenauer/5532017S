/*Nicole Regenauer
HW2f: Array statistics
I pledge my honor that I have abided by the Stevens Honor System
*/

#include <iostream>
#include <fstream>
using namespace std;

void stats(int a[], int n, double& mean, double& var, double& min, double& max){
  min=a[0];
  max=a[0];
  mean=0;
  var=0;
  int counter = n-1;
  while(counter>=0){
    mean+=a[counter];
    if (a[counter] >= max){
      max = a[counter];
    }
    if(a[counter]<=min){
      min = a[counter];
    }
    counter--;
  }
  mean=mean/n;
  counter=n-1;
  while(counter>=0){
    var += (a[counter]-mean)*(a[counter]-mean);
    counter--;
  }
  var=var/n;
}


int main(){
  int line;
  int size=0;
  ifstream myfile;
  myfile.open("2f.dat");
  while (myfile >> line){
    if(size==0)
      size = line;
    break;
  }
  int local = size;
  int array[size];
  int i = 0;
  while (myfile >> line && size > 0){
    array[i]=line;
    size--;
    i++;
  }
  double mean;
  double var;
  double min;
  double max;
  stats(array,local,mean,var,min,max);
  cout << "Average is: " << mean << endl;
  cout << "Variance is: " << var << endl;
  cout << "Minimum value is: " <<  min << endl;
  cout << "Maximum value is: " << max << endl;
}
