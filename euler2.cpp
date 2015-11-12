// problem: https://projecteuler.net/problem=2
// Minsuk (Luke) Kim
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 

// from prior calculations, realised that the 33rd fibonacci number 
// exceeds four million.  
typedef unsigned long long ull;
ull fib[1000] = {1,2}; 
 
int main(){
	ull sum = 0; 
	for (int i = 2; i < 32; i++){
		fib[i] = fib[i-1] + fib[i-2];
	}
	for (int i = 0; i < 32; i++){
		if (fib[i]%2 == 0){
			sum += fib[i]; 
		}
	}
	cout << sum << endl;
}
