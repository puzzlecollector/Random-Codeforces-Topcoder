// Problem Link: https://projecteuler.net/problem=4
// brute force method 
#include <iostream>
#include <cstdlib>
#include <string> 
#include <sstream> 
#include <algorithm> 
using namespace std; 

bool isPalindrome(string s){
	for (int i = 0; i < s.length()/2; i++){
		if (s[i] != s[s.length()-i-1]) return false; 
	}
	return true;  
}

string convertInt(int n){
	stringstream ss; 
	ss << n; 
	return ss.str(); 
}

int main(){
	int prod = 1; 
	int maxI = 100, maxJ = 100; 
	for (int i = 100; i <= 999; i++){
		for (int j = 100; j <= 999; j++){
			if (i*j > prod && isPalindrome(convertInt(i*j))){
				prod = i*j; 
				maxI = i; 
				maxJ = j; 
			}
		}
	}
	cout << maxI*maxJ << endl;
	return 0; 
}
