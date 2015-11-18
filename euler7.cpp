/*
Problem link: https://projecteuler.net/problem=7
From prime counting function π(x) = x/lnx, we know that when 
x ~ 10^6, we have nearly 80000 prime numbers (78498 to be exact), so let's reasonably 
loop for about 10^6 times. This algorithm would have time complexity O(1). 
Now Sieve of eratosthenes again...  

In this version I can just get the answer directly by compiling the program. 
*/
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std; 

#define MAXN 1000000 
int notPrime[MAXN];  // all initialized to 0. 
int cnt = 0; 

void eratos(){
	notPrime[0] = notPrime[1] = 1;  // 0,1 are not primes, so mark as true. 
	for (int i = 2; i*i <= MAXN; i++){
		if (!notPrime[i]){
			for (int j = i*i; j <= MAXN; j += i){
				notPrime[j] = 1; 
			}
		}
	}
}

int main(){
	eratos(); 
	for (int i = 1; i <= 1000000; i++){
		if (!notPrime[i]){
			if (cnt++ == 10001){
				cout << i << endl;
				break; 
			}
		}
	}
	return 0; 
}
