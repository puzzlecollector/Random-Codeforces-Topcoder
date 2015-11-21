/*
Problem Link: https://algospot.com/judge/problem/read/TILING2
타일을 하는 방법을 다음과 같이 생각해보자: 가장 왼쪽 세로줄을 가로 타일 두개로 채우거나 세로 타일 
하나로 채운다. 이 방법을 이용하면, 다음과 같은 recursive function 을 얻을 수 있다:  
tiling(n) = tiling(n-1)+tiling(n-2) 
이 함수는 참조적 투명 함수이므로, memoization을 적절히 적용한다. 
*/

#include <iostream>
#include <cstdlib>
#include <cmath> 
#include <algorithm> 
#include <cstring> 
using namespace std; 

const int MOD = 1000000007; 
int c,n; 
int cache[101]; 
int tiling(int width){
	if (width <= 1){
		return 1;  
	}
	int& ret = cache[width]; 
	if (ret != -1) return ret; 
	return ret = (tiling(width-1)+tiling(width-2))%MOD;  
}

int main(){
	cin >> c; 
	for (int i = 0; i < c; i++){
		cin >> n; 
		memset(cache,-1,sizeof(cache)); 
		int ans = tiling(n); 
		cout << ans << endl; 
	}
	return 0; 
}
