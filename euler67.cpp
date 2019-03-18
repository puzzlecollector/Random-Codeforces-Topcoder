#include <iostream>
#include <cstring>
#include <cstdio>
#include <fstream>
#include <algorithm>
using namespace std;
int a[105][105];
int cache[105][105];
int solve(int x,int y){
  if (x == 100) return a[x][y];
  int &ret = cache[x][y];
  if (ret != -1) return ret;
  return ret = a[x][y]+max(solve(x+1,y),solve(x+1,y+1));
}
int main(){
  fstream fin("tri.txt");
  memset(cache,-1,sizeof(cache));
  for (int i = 1; i <= 100; i++){
    for (int j = 1; j <= i; j++){
      fin >> a[i][j];
    }
  }
  int ans = solve(1,1);
  return !printf("%d\n",ans);
}
