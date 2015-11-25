/*
Problem Link: https://projecteuler.net/problem=15
For this problem, for each lattice point, we know that the number of ways of visiting 
that lattice point depends on the number of ways of visiting the lattice point directly 
above it and to the left of it. 
So for lattice point (i,j), we have the following recursion: 
no(i,j) = no(i-1,j)+no(i,j-1)
*/
#include <iostream>
#include <cstdlib> 
#include <algorithm> 
#include <cstring> 
#include <cmath> 
using namespace std; 

long long dp[21][21];  

int main(){
	for (int i = 0; i < 21; i++){
		dp[0][i] = 1; 
		dp[i][0] = 1; 
	}
	for (int i = 1; i < 21; i++){
		for (int j = 1; j < 21; j++){
			dp[i][j] = dp[i-1][j] + dp[i][j-1]; 
		}
	}
	cout << dp[20][20] << endl; 
	return 0; 
}
