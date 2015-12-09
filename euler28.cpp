/*
Problem Link: https://projecteuler.net/problem=28
Define f(n) to be the sum of the diagonals, then we find the recursive relationship 
f(n) = 4(2n+1)^2 - 12n + f(n-1), where f(0) = 1. 
*/
#include <iostream> 
#include <cmath> 
#include <cstdio> 
#include <algorithm> 
using namespace std; 

int main(){
	int dp[501];
	dp[0] = 1; 
	for (int i = 1; i <= 500; i++){
		dp[i] = dp[i-1] + 4*(2*i+1)*(2*i+1) - 12*i; 
	} 
	cout << dp[500] << endl; 
	return 0; 
}

