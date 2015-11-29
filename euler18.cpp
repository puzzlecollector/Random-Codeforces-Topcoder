/*
Problem Link: https://projecteuler.net/problem=18
This problem involves finding the maximum total from top to bottom of the given triangle. 
This is a classic DP problem. 
*/
#include <iostream>
#include <cstdlib> 
#include <cmath> 
#include <string> 
using namespace std; 

int triangle[15][15]; 

int main(){
	// getting input from console 
	for (int i = 0; i < 15; i++){
		for (int j = 0; j <= i; j++){
			cin >> triangle[i][j]; 
		}
	}
	// dp algorithm 
	for (int i = 13; i >= 0; i--){
		for (int j = 0; j <= i; j++){
			triangle[i][j] += max(triangle[i+1][j],triangle[i+1][j+1]);
		}
	}
	// getting result 
	cout << triangle[0][0] << endl; 
	return 0; 
}
