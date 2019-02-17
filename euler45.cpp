/*
Find the next triangle number that is also pentagonal and hexagonal.
*/
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
int main(int argc,char **argv){
  for (double i = 286;;i++){
    double k = i*(i+1)/2.0;
    double pent = (1+sqrt(1+24*k))/6.0;
    double hex = (1+sqrt(1+8*k))/4.0;
    double intpart1,intpart2;
    if (modf(pent,&intpart2) == 0.0 && modf(hex,&intpart2) == 0.0){
      cout.setf(ios::showpoint);
      cout.setf(ios::fixed);
      cout.precision(15); 
      cout << k << endl;
      return 0;
    }
  }
  return 0;
}
