// Problem A.
// Problem Link: http://codeforces.com/contest/609/problem/A
// this is a problem involving greedy algorithm. We choose the flash drives with the largest size 
// first and use it to write sean's file. 
#include <iostream> 
#include <cstdlib> 
#include <vector>
#include <algorithm>  
using namespace std; 

int n,m,a; 
vector<int> v; 

int main(){
	cin >> n >> m; 
	for (int i = 0; i < n; i++){
		cin >> a; 
		v.push_back(a);  
	}	
	sort(v.begin(),v.end(),greater<int>()); 
	int sum = 0; 
	for (int i = 0; i < v.size(); i++){
		sum += v[i]; 
		if (sum >= m){
			cout << i+1 << endl; 
			break; 
		}
	}
	return 0; 
}

// By Minsuk Luke Kim (lukekms)
