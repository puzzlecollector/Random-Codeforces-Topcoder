// problem link: https://projecteuler.net/problem=3 
// basic application of the sieve of eratosthenes
// Minsuk (Luke) Kim
#include <iostream>
#include <cstdlib>
#include <cmath> 
using namespace std; 
#define MAXN 1000000

typedef unsigned long long ull; 

ull num = 600851475143; 
int notPrime[MAXN];  // all initialized to zero. 

void eratos(int n){
	notPrime[0] = notPrime[1] = 1; // 1 is not a prime. 
	for (int i = 2; i*i <= n; i++){
		if (!notPrime[i]){
			for (int j = i*i; j <= n; j += i){
				notPrime[j] = 1;  
			}
		}
	}
}


int main(){
	int ans; 
	int upperbound = sqrt(num); 
	eratos(upperbound); 
	for (int i = 2; i <= upperbound; i++){
		if (!notPrime[i] && num%i == 0){
			ans = i; 
		}
	}
	cout << ans << endl; 
	return 0; 
}

