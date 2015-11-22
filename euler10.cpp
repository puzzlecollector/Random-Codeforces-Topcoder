/*
Problem link: https://projecteuler.net/problem=10
Sieve of erastosthenes yet again. The application is much simpler this time though. 
If you solve 10 problems, you earn a decathlete badge lol! 
*/
#include <iostream>
#include <cstdlib>
using namespace std; 

#define MAXN 2000000

int notPrime[MAXN];  

void eratos(){
	notPrime[0] = notPrime[1] = 1; 
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
	long long sum = 0; 
	for (int i = 1; i <= MAXN; i++){
		if (!notPrime[i]){
			// cout << i << endl;
			sum += i; 
		}
	}
	cout << sum << endl;
	return 0; 
}
