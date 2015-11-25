/*
Problem Link: https://projecteuler.net/problem=14
Counting the length of the chain of a collatz sequence.  
This is a direct approach that takes about 2~3 seconds to produce an answer. 
*/
#include <iostream> 
#include <cstdlib> 
#include <algorithm> 
#include <cstdio> 
#include <cstring>
using namespace std;  


int collatzLen(long long n){
	int len = 1; 
	while (n > 1){
		++len; 
		if (n%2 == 0) n /= 2;  
		else if (n%2 == 1) n = 3*n + 1; 
	}
	return len; 
}


int main(){
	
	int maxi = 0, largestLen = 0;  
	for (int i = 1; i < 1000000; i++){
		int val = collatzLen(i); 
		if (val > maxi){
			maxi = val;  
			largestLen = i; 
		}
	}
	cout << largestLen << endl;
	return 0; 
}
