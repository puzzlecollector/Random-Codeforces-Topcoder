/*
Problem Link: http://codeforces.com/contest/610/problem/B
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
