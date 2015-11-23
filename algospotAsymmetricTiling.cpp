/*
Problem Link: https://algospot.com/judge/problem/read/ASYMTILING 
We find the number of ways of tiling a 2 by n rectangle with 2 by 1 rectangles such that 
the tiles are arranged asymmetrically. 

One possible method of solving the problem would be to find the number of ways of arranging the tiles symmetrically, 
and then subtracting that number from the total number of ways of tiling. 
*/
#include <iostream> 
#include <cstdlib>
#include <algorithm> 
#include <cstring> 
using namespace std; 

#define MOD 1000000007

int c,n; 
int cache[101]; 

int tiling(int width){
	if (width <= 1){
		return 1; 
	}
	int& ret = cache[width]; 
	if (ret != -1) return ret; 
	ret = (tiling(width-1) + tiling(width-2))%MOD; 
	return ret;  
}

int asym(int width){
	if (width%2 == 1){
		return (tiling(width) - tiling(width/2) + MOD)%MOD; 
	}
	int ret = tiling(width); 
	ret = (ret - tiling(width/2 - 1) + MOD)%MOD;
	ret = (ret - tiling(width/2) + MOD)%MOD; 
	return ret;   
}

int main(){
	cin >> c; 
	for (int i = 0; i < c; i++){
		cin >> n; 
		memset(cache,-1,sizeof(cache)); 
		int ans = asym(n);  
		cout << ans << endl; 
	}
	return 0; 
}

