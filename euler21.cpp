/*
Problem Link: https://projecteuler.net/problem=21 
naive approach 
Should run quickly because we are only looking at amicable numbers 
strictly less than 10000.  
Could use some pruning but nevermind lol. 
*/

#include <iostream> 
#include <vector> 
#include <cmath> 
#include <algorithm> 
using namespace std;  

int main(){
	int sumAmicable = 0; 	
	for (int i = 1; i < 10000; i++){
		int sumA = 0, sumB = 0;  
		for (int j = 1; j*j <= i; j++){
			if (i%j == 0){
				if (j == (i/j)) sumA += j; 
				else sumA += j + (i/j); 
			}
		}
		sumA -= i; 
		for (int j = 1; j*j <= sumA; j++){
			if (sumA%j == 0){
				if (j == sumA/j) sumB += j; 
				else sumB += j + (sumA/j); 
			}
		}
		sumB -= sumA;  
		if (sumB == i && (sumA != sumB)){
			// note that amicable pairs should not be the same 
			// because then amicable numbers will also include perfect numbers (e.g. 6,28,...)
			sumAmicable += i; 
		}
	}
	cout << sumAmicable << endl; 
	return 0;  
}
