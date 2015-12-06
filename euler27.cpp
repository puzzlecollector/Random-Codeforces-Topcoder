/*
Problem Link: https://projecteuler.net/problem=27
Not a very smart brute force, but the method works in 1~2 seconds
Beware of negative values - negative numbers cannot be prime so exclude them from our calculations. 
*/
#include <iostream>
#include <cstdlib>
#include <cstdio> 
#include <vector> 
#include <algorithm> 
using namespace std;

bool isPrime(int n){
	for (int i = 2; i*i <= n; i++){
		if (n%i == 0) return false; 
	}
	return n != 1; 
}


int main(){
	int maxProd = 0, maxCnt = 0;  
	for (int a = -999; a < 1000; a++){
		for (int b = -999; b < 1000; b++){
			int cnt = 0; 
			for (int n = 0;;n++){
				int val = n*n + a*n + b; 
				if (isPrime(val) && val > 0){
					++cnt; 
				}else break; 
			}
			if (maxCnt < cnt){
				maxCnt = cnt;  
				maxProd = a*b;  
			}
		}
	}
	cout << maxCnt << endl; 
	cout << maxProd << endl;  // this is our answer! :)
	return 0; 
} 
