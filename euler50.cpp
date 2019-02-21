#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1e6+5;
int prime[maxn];
typedef long long ll;
void eratos(){
  for (int i = 0; i < maxn; i++){
    prime[i] = 1;
  }
  prime[0] = prime[1] = 0;
  for (ll i = 2; i < maxn; i++){
    if (prime[i]){
      for (ll j = i*i; j < maxn; j += i){
        prime[j] = 0;
      }
    }
  }
}
ll psum[maxn];
int main(){
  eratos();
  vector<ll> v;
  for (int i = 0; i < maxn; i++){
    if (prime[i]) v.push_back(i);
  }
  psum[0] = v[0];
  for (int i = 1; i < v.size(); i++){
    psum[i] = psum[i-1]+v[i];
  }
  int maxlen = 21;
  int ans = 953;
  for (int k = 22; k <= 600; k++){ // because psum[600] > 1e6 
    for (int i = 0; i+k-1 < v.size(); i++){
      ll x = 0;
      if (i == 0) x = psum[i+k-1];
      else x = psum[i+k-1]-psum[i-1];
      if (x <= 1e6 && prime[x] && k > maxlen){
        maxlen = k;
        ans = x;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
