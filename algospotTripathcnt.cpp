/*
Problem Link: https://algospot.com/judge/problem/read/TRIPATHCNT 
먼저 바탕이 되는 최적화 문제를 해결하고, 각 부분 문제마다 최저해의 개수를 계산하는 동적 
계획법 알고리즘을 만든다. 
*/

#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <cstring> 
using namespace std; 

int triangle[100][100]; 
int cache[100][100];  
int countCache[100][100];  
int n,c; 

int path(int y, int x){
	if (y == n-1) return triangle[y][x];  
	// memoization 
	int& ret = cache[y][x];  
	if (ret != -1) return ret; 
	ret = max(path(y+1,x+1),path(y+1,x)) + triangle[y][x]; 
	return ret; 
}

int count(int y, int x){
	if (y == n-1) return 1; // found one path that reaches the end. 
	// memoization 
	int& ret = countCache[y][x];  
	if (ret != -1) return ret; 
	ret = 0;  
	if (path(y+1,x+1) >= path(y+1,x)) ret += count(y+1,x+1);  
	if (path(y+1,x+1) <= path(y+1,x)) ret += count(y+1,x);  
	return ret; 
}

int main(){
	cin >> c; 
	for (int i = 0; i < c; i++){
		memset(cache,-1,sizeof(cache)); 
		memset(countCache,-1,sizeof(countCache));  
		cin >> n; 
		for (int j = 0; j < n; j++){
			for (int k = 0; k <= j; k++){
				cin >> triangle[j][k];  
			}
		}
		int ans = count(0,0); 
		cout << ans << endl; 
	}
	return 0; 
}
