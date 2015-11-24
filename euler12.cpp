/*
Problem Link: https://projecteuler.net/problem=12 
In this problem, we find the first triangle number to have over 
500 divisors. 
We use a mathematical formula for find the number of factors
- first prime factorize the given number. 
- find the exponents of each of the prime number. Suppose 
they are a1,a2,...,an 
- then the number of divisors is 
(a1+1)(a2+1)...(an+1);    
*/
#include <iostream>
#include <cstdlib> 
#include <algorithm> 
#include <cstdio> 
#include <map> 
using namespace std;  

map<int,int> res; 

int nthTriangleNumber(int n){
	return (n)*(n+1)/2; 
}

// can be implement to run in O(sqrt(n))
void primeFactorization(int n){
	for (int i = 2; i*i <= n; i++){
		while (n%i == 0){
			++res[i]; 
			n /= i;  
		}
	}
	if (n != 1) res[n] = 1;  
}

int numberofDivisors(){
	int prod = 1;  
	for (map<int,int>::iterator it = res.begin(); it != res.end(); it++){
		prod *= (it->second+1);  
	}
	return prod; 
} 

void clearMap(){
	res.clear(); 
}

int main(){
	for (int i = 2;;i++){
		int num = nthTriangleNumber(i);  
		primeFactorization(num); 
		if (numberofDivisors() >= 500){
			cout << nthTriangleNumber(i) << endl; 
			break; 
		}
		clearMap(); // initialize map after every calculation we do. 
	}
	return 0; 
}
