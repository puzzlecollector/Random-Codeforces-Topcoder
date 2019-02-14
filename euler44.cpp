#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
// P_n = n(3n-1)/2
set<int> st;
vector<int> v;
int main(int argc,char **argv){
  for (int i = 1; i <= 10000; i++){
    st.insert(i*(3*i-1)/2);
    v.push_back(i*(3*i-1)/2);
  }
  for (int i = 0; i < v.size(); i++){
    for (int j = i+1; j < v.size(); j++){
      if (st.count(v[i]+v[j]) && st.count(v[j]-v[i])){
        cout << v[j]-v[i] << endl;
        return 0;  
      }
    }
  }
}
