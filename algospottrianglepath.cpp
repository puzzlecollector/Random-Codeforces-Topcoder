/*
Problem link: https://algospot.com/judge/problem/read/TRIANGLEPATH
부분 문제의 갯수: n^2,  한 문제를 푸는데 걸리는 시간: 상수시간  
시간복잡도: O(n^2)*O(1) = O(n^2). 
*/
#include <iostream>
#include <cstdlib> 
#include <cstring> 
#include <algorithm> 
using namespace std;

int c,n;  
int cache[100][100];  
int triangle[100][100];  

int path(int y, int x){
	if (y == n-1) return triangle[y][x];  
	// memoization
	int& ret = cache[y][x];  
	if (ret != -1) return ret; 
	return ret = max(path(y+1,x),path(y+1,x+1))+triangle[y][x]; 
}

int main(){
	cin >> c; 
	for (int i = 0; i < c; i++){
		memset(cache,-1,sizeof(cache));  
		cin >> n; 
		for (int j = 0; j < n; j++){
			for (int k = 0; k <= j; k++){
				cin >> triangle[j][k];  
			}
		}
		int ans = path(0,0); 
		cout << ans << endl; 
	}
	return 0; 
}
