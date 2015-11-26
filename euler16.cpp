/*
Problem Link: https://projecteuler.net/problem=16
Finding the sum of the digits of 2^1000  
We have to simluate the multiplication process of numbers. 
We can mathematically estimate that there are log(2^1000) + 1 digits 
so reserving 700 slots in our vector would be more than enough 
(that expression above should evaluate to something in between 600 to 700 I guess)

I used vector rather than string to simulate multiplication. 
*/
#include <iostream>
#include <cstdlib> 
#include <cstdio> 
#include <algorithm> 
#include <vector> 
using namespace std;  

vector<int> num(700); // vector initialized to contain 700 zeroes. 

vector<int> normalize(vector<int>& v){
	for (int i = 0; i < v.size()-1; i++){
		if (v[i] >= 10){
			v[i] %= 10; 
			++v[i+1]; 
		}
	}
	return v;  
}

vector<int> multiplyby2(vector<int>& v){
	for (int i = 0; i < v.size(); i++){
		v[i] *= 2;  
	}
	vector<int> ret = normalize(v);  
	return ret;  
}

int main(){
	num[0] = 1; // then we will have {1,0,0,...} 
	// in our vector. 
	for (int i = 0; i < 1000; i++){
		multiplyby2(num); 
	}
	// after this process, our vector will contain the number in reverse order.  
	// e.g. if it is 16, then it will contain {6,1} etc. 
	// now we find the sum of these numbers in the vector. 
	int sum = 0; 
	for (int i = 0; i < num.size(); i++){
		sum += num[i]; 
	} 
	cout << sum << endl; 
	return 0; 
}
