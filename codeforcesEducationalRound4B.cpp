// Problem Link: http://codeforces.com/contest/612/problem/B
// really easy for problem B, we just sort the fragments and then find the adjacent distances 
// and add them all up. 
#include <iostream> 
#include <cstdlib> 
#include <algorithm> 
#include <utility> 
#include <vector> 
using namespace std;  

vector< pair<int,int> > v;  

int main(){
	int n,fragments; 
	cin >> n;  
	for (int i = 0; i < n; i++){
		cin >> fragments; 
		v.push_back(make_pair(fragments,i+1)); 
	}	
	sort(v.begin(),v.end());  
	int t = 0; // time.  
	for (int i = 0; i < v.size()-1; i++){
		t += abs(v[i].second - v[i+1].second);  
	}
	cout << t << endl; 
	return 0; 
}
