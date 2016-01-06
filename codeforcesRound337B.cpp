/*
Problem Link: http://codeforces.com/contest/610/problem/B
Problem Analysis: Because n can be at most 200000, it is not a good idea to brute force our solution.  
Now, we note that the answer should actually depend on the number of minimum values of the given array. 
If the array contains a single minimum value, then we can start with the pain directly after the minimum value, 
but if the array contains more than one minimum value, then we have to find the two minimum values that are furthest apart 
and then add that distance to the value n*minimum value. This is because we can iterate at least n*minimum value times, and 
we can iterate (max distance between two minimums) times more. 
*/ 
#include <iostream> 
#include <cstdlib> 
#include <cstring> 
#include <algorithm> 
using namespace std; 

int main(){
	long long n,m = 2e9,cnt=0,s=0; 
	cin >> n; 
	long long a[n]; 
	for (long long i = 0; i < n; i++){
		cin >> a[i]; 
		m = min(m,a[i]); 
	}
	for (long long i = 0; i < 2*n; i++){
		if (a[i%n] == m){
			s = max(s,cnt); 
			cnt = 0;  
		}else{
			++cnt; 
		}
	}
	cout << s+m*n << endl; 
	return 0; 
}
