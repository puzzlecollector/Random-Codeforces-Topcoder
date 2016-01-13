/*
Problem Link: http://codeforces.com/contest/615/problem/A
Brute force solution 
*/
#include <iostream>
#include <cstdlib> 
using namespace std; 

int bulbsOn[102]; 

int main(){
	int n,m,x,y; 
	cin >> n >> m;  
	for (int i = 0; i < n; i++){
		cin >> x; 
		for (int j = 0; j < x; j++){
			cin >> y;  
			bulbsOn[y] = 1; 
		}
	}
	for (int i = 1; i <= m; i++){
		if (!bulbsOn[i]){
			cout << "NO" << endl; 
			return 0; 
		}
	}
	cout << "YES" << endl; 
	return 0; 
}
