/*
Problem Link: https://projecteuler.net/problem=30
Another brute force problem, but in order to solve this problem we must first determine the upper bound we are going to use. 
Note that for 5 digits, the sum of fifth powers of digits is at most 5*9^5 and this is a six digit number. And 6*9^5 is also a six digit number, 
and 7*9^5 is also a six digit number (but in this case the number of digits we have are seven). This means that we can search up to approximately
6*9^5
*/
#include <iostream> 
#include <algorithm> 
#include <cstdlib> 
#include <cmath> 
#include <numeric> 
#include <vector> 
using namespace std; 

int upper = 6*9*9*9*9*9 + 100; 

int fifthDigitSum(int n){
	int sum = 0;  
	while (n){
		sum += pow(n%10,5); 
		n /= 10; 
	}
	return sum; 
}

int main(){
	vector<int> v; 
	for (int i = 2; i <= upper; i++){
		int num = i; 
		if (num == fifthDigitSum(num)){
			v.push_back(num); 
		}
	}	
	int ans = accumulate(v.begin(),v.end(),0); 
	cout << ans << endl;
	return 0; 
}	
