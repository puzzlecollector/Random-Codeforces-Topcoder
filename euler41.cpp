#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <vector> 
#include <sstream> 
using namespace std; 
int toInt(string s){
	istringstream iss (s); 
	int n; 
	iss >> n; 
	return n;  
}
bool isPrime(int x){
	for (int i = 2; i*i <= x; i++){
		if (x%i == 0) return false;  
	}
	return x != 1; 
}
void permute(int l,int r,string t,vector<string> &v){
	if (l == r){
		v.push_back(t); 
		return;  
	}
	for (int i = l; i <= r; i++){
		swap(t[l],t[i]); 
		permute(l+1,r,t,v); 
		swap(t[l],t[i]); 
	}
}
int main(){ 
	int ans = 0;  
	for (int i = 1; i <= 9; i++){
		string t = ""; 
		for (int j = 1; j <= i; j++){
			t += char(j+'0'); 
		}
		vector<string> v; 
		permute(0,t.size()-1,t,v); 
		for (int j = 0; j < v.size(); j++){
			if (isPrime(toInt(v[j]))){
				ans = max(ans,toInt(v[j]));  
			}
		}
	}
	cout << ans << endl; 
	return 0;  
}
