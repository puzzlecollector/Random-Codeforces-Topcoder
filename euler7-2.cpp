/*
Problem link: https://projecteuler.net/problem=7
From prime counting function π(x) = x/lnx, we know that when 
x ~ 10^6, we have nearly 80000 prime numbers (78498 to be exact), so let's reasonably 
loop for about 10^6 times. This algorithm would have time complexity O(1). 
Now Sieve of eratosthenes again...  

In this version I wrote all the primes to a txt file and viewed it in sublime text2 
(or could be some other editor with line no), 
and simply looked at line number 10001 to get the answer. 
*/
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std; 

#define MAXN 1000000 
int notPrime[MAXN];  // all initialized to 0. 

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
	ofstream myfile("euler7.txt"); 
	if (!myfile.is_open()){
		cout << "couldn't open file" << endl;
	}
	eratos(); 
	for (int i = 1; i <= 1000000; i++){
		if (!notPrime[i]){
			myfile << i << endl;
		}
	}
	myfile.close(); 
	return 0; 
}
