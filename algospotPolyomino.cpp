/*
Problem Link: https://algospot.com/judge/problem/read/NPOLY
poly(n,first) = sum_{second = 1,...,second = n-first}(second + first -1)*poly(n-first,second) 
점화식을 이용한다. 
시간복잡도는 부분문제의 갯수 * 한 부분문제를 처리하는데 걸리는 시간 = O(n^2)*O(n) = O(n^3)이다. 
*/
#include <iostream> 
#include <cstdlib>
#include <cstring> 
#include <algorithm> 
#include <cmath> 
using namespace std;  

int no,c;  
const int MOD = 10*1000*1000;
int cache[101][101];  

int poly(int n, int first){
	// 기저: n == first 
	if (n == first) return 1; 
	// memoization 
	int& ret = cache[n][first];  
	if (ret != -1) return ret;  
	ret = 0;  
	for (int second = 1; second <= n-first; second++){
		int add = first+second-1; 
		add *= poly(n-first,second); 
		add %= MOD; 
		ret += add; 
		ret %= MOD;  
	}
	return ret;  
}

int main(){
	cin >> c; 
	for (int i = 0; i < c; i++){
		cin >> no; 
		int ans = 0; 
		for (int j = 1; j <= no; j++){
			memset(cache,-1,sizeof(cache)); 
			ans += poly(no,j); 
			ans %= MOD; 
		}
		cout << ans << endl; 
	}
	return 0; 
}
