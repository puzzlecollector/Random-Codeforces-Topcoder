#include <iostream>
#include <cmath> 
#include <cstdlib>
using namespace std;  
int prime[1111111];  
void sieve(){
	for (int i = 0; i < 1111111; i++){
		prime[i] = 1;  
	}
	prime[0] = prime[1] = 0; 
	for (int i = 2; i*i <= 1111111; i++){
		if (prime[i]){
			for (int j = i*i; j <= 1111111; j += i){
				prime[j] = 0;  
			}
		}
	}
}
bool isCircularPrime(int x){
	int len = 0;  
	int temp = x;  
	while (temp){
		temp /= 10; 
		len++; 
	}
	for (int i = 0; i < len; i++){
		if (!prime[x]) return false;  
		x = (x/10)+pow(10,len-1)*(x%10); 
	}
	return true;  
}	
int main(){
	sieve();  
	int cnt = 0; 
	for(int i = 1; i <= 1000000; i++){
		if (isCircularPrime(i)){
			cnt++; 
		}
	}
	cout << cnt << endl; 
	return 0; 
}
