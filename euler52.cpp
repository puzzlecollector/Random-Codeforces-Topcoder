#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int main(int argc,char **argv){
  for (int i = 1; i < 1000000; i++){
    vector<int> v;
    for (int j = i; j <= 6*i; j += i){
      v.push_back(j);
    }
    map<int,int> a[6];
    for (int j = 0; j < v.size(); j++){
      map<int,int> temp;
      int t = v[j];
      while (t){
        temp[t%10]++;
        t /= 10;
      }
      a[j] = temp;
    }
    if (a[0] == a[1] && a[1] == a[2] && a[2] == a[3] &&
    a[3] == a[4] && a[4] == a[5]){
      return !printf("%d\n",i); 
    }
  }
  return 0;
}
