/*
Problem link: https://projecteuler.net/problem=5
for all prime factors less than or equal to n, find the highest power of that prime factor 
not exceeding n, and multiply the altogether. 
*/

#include <iostream>
#include <cstdlib>
using namespace std; 

// O(sqrt(n))
bool isPrime(int n){
	for (int i = 2; i*i <= n; i++){
		if (n%i == 0) return false; 
	}
	return n != 1;  
}

// evaluate a^x 
// O(lg(x))
// use this function instead of std::pow()
int fastExpo(int a, int x){
	if (x == 0) return 1; 
	if (x == 1) return a; 
	return fastExpo(a,x/2)*fastExpo(a,x/2)*fastExpo(a,x%2);  
}


int main(){
	int prod = 1;  
	for (int i = 1; i <= 20; i++){
		if (isPrime(i)){
			int cnt = 1, mult; 
			while (fastExpo(i,cnt) <= 20){
				mult = fastExpo(i,cnt);   
				++cnt;  
			}
			prod *= mult;  
		}
	}
	cout << prod << endl;
	return 0; 
}
