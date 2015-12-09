/*
Problem Link: https://projecteuler.net/problem=31
Using dp approach. 
*/

#include <iostream> 
#include <cstdlib> 
#include <cmath> 
#include <cstring> 
#include <algorithm> 
using namespace std; 

int coinTypes[8] = {1,2,5,10,20,50,100,200};  
int dp[201]; 

int main(){
	dp[0] = 1; 
	for (int i = 0; i < 8; i++){
		for (int j = coinTypes[i]; j <= 200; j++){
			dp[j] += dp[j-coinTypes[i]]; 
		}
	}
	cout << dp[200] << endl; 
	return 0; 
}
