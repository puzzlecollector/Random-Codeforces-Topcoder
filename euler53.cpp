#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 101;
const int MAXR = 101;
const int INF = (int)1e6;
int bino[MAXN][MAXR];
void calculate(){
  for (int i = 0; i < MAXN; i++){
    for (int j = 0; j <= i; j++){
      if (j == 0 || j == i) bino[i][j] = 1;
      else{
        bino[i][j] = min(INF,bino[i-1][j-1]+bino[i-1][j]);
      }
    }
  }
}
int main(int argc,char **argv){
  calculate();
  int cnt = 0;
  for (int i = 0; i < MAXN; i++){
    for (int j = 0; j < MAXR; j++){
      if (bino[i][j] >= INF) cnt++;
    }
  }
  return !printf("%d\n",cnt);
}
