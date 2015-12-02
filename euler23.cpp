/*
Problem Link: https://projecteuler.net/problem=23
The problem is to find the sum of all psotive integers that cannot be written as the sum of two abundant numbers. 
Find all abundant numbers. Find all possible sums using the abundant numbers found. 
Add all numbers to a variable sum if that number is not in the list of numbers that can be 
made by adding up two abundant numbers. 
*/
#include <iostream> 
#include <cstdlib>
#include <algorithm> 
#include <cmath> 
#include <vector> 
using namespace std; 

int isSumAbundant[28125]; // initially all zero.  

int sumDivisors(int n){
	int sum = 0;  
	for (int i = 1; i*i <= n; i++){
		if (n%i == 0){
			if (i == (n/i)) sum += i; 
			else sum += i + (n/i); 
		}
	}
	sum -= n; 
	return sum;  
}

int main(){
	vector<int> abundant;  
	// find all abundant numbers. 
	for (int i = 1; i <= 28213; i++){
		if (sumDivisors(i) > i){
			abundant.push_back(i);
		}	
	}
	// find the values that can be expressed as the sum of two abundant numbers.  
	// O(n^2) but the abundant.size() is small enough that the program will run quickly. 
	for (int i = 0; i < abundant.size(); i++){
		for (int j = 0; j < abundant.size(); j++){
			int val = abundant[i]+abundant[j]; 
			if (val <= 28123){
				isSumAbundant[val] = 1;  
			}
		}
	}
	int ans = 0; 
	for (int i = 0; i < 28124; i++){
		if (!isSumAbundant[i]){
			ans += i;  
		}
	}
	cout << "ans: " << ans << endl; 
	return 0; 
}
