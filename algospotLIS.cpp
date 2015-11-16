/*
Problem Link: https://algospot.com/judge/problem/read/LIS
부분문제 O(n)개, 그리고 한 문제를 해결할때마다 O(n)번 호출되기 때문에 총 
O(n^2)시간이 걸린다. 
*/
#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <cstring> 
using namespace std; 

int a[500]; 
int dp[500];  

int main(){
	int c,n;
	cin >> c; 
	for(int i = 0; i < c; i++){
		int res = 0;  
		cin >> n; 
		for (int j = 0; j < n; j++){
			cin >> a[j];  
		}
		for (int j = 0; j < n; j++){
			dp[j] = 1;  
			for (int k = 0; k < j; k++){
				if (a[k] < a[j]){
					dp[j] = max(dp[j],1+dp[k]);  
				}
			}
			res = max(res,dp[j]);  
		}
		cout << res << endl; 
	}
	return 0; 
}
