#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
const int MAXN = 1e5 + 5;
int prime[MAXN];
typedef long long ll;
void eratos(){ // sieve of erastosthenes
  for (int i = 0; i < MAXN; i++){
    prime[i] = 1;
  }
  prime[0] = prime[1] = 0;
  for (ll i = 2; i < MAXN; i++){
    if (prime[i]){
      for (ll j = i*i; j < (ll)MAXN; j += i){
        prime[j] = 0;
      }
    }
  }
}
int main(int argc,char **argv){
  eratos();
  for (int i = 9;; i += 2){
    if (!prime[i]){
      bool passed = false;
      for (int j = 1; j <= i; j++){
        int temp = i;
        if (prime[j] && (temp-j)%2 == 0){
          temp -= j;
          temp /= 2;
          double intpart;
          double k = sqrt((double)temp);
          if (modf(k,&intpart) == 0.0){
            passed = true;
            break;
          }
        }
      }
      if (!passed){
        return !printf("%d\n",i);
      }
    }
  }
  return 0;
}
