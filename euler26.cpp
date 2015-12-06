/*
Problem Link: https://github.com/iljimae0418/Random-Codeforces-Topcoder/blob/master/RepeatingDecimal.cpp
Simulate the division process. We could either generate a string of repeating decimals and count longest repeating substring 
(difficult to implement...) or use std::map to store when we see each dividend.  
*/

#include <iostream> 
#include <cstdlib> 
#include <map> 
#include <string> 
#include <algorithm> 
using namespace std;  

int cycleLen(int denominator){
	map<int,int> m; 
	int numerator = 1; 
	int len = 0;  
	while (!m.count(numerator)){
		m.insert(pair<int,int>(numerator,len));  
		numerator = (numerator%denominator)*10;  
		++len; 
	}
	return len-m[numerator]; 
}

int main(){
	int maxLen = 0, maxd;
	for (int i = 2; i < 1000; i++){
		int len = cycleLen(i); 
		if (maxLen < len){
			maxLen = len;  
			maxd = i; 
		}
	} 
	cout << maxd << endl; 
	return 0; 
}
