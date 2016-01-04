// Problem Link: http://codeforces.com/contest/610/problem/A
#include <iostream> 
#include <cstdlib> 
#include <cstring> 
#include <algorithm> 
#include <cstdio>  
using namespace std; 

int main(){
	int n;
	cin >> n;
	if (n%2 == 1){
		cout << 0 << endl; 
	}else{
		if (n%4 == 0){
			cout << (n/4)-1 << endl; 
		}else{
			cout << (n/4) << endl; 
		}
	}
	return 0; 
}
