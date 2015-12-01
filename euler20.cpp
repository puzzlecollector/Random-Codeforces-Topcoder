/*
Problem Link: https://projecteuler.net/problem=20
simulate big number multiplication using std::vector
*/

#include <iostream>
#include <string> 
#include <sstream> 
#include <vector> 
#include <algorithm> 
using namespace std; 

string intToString(int n){
	stringstream ss; 
	ss << n; 
	return ss.str(); 
}

vector<int> normalize(vector<int>& v){
	for (int i = 0; i < v.size(); i++){
		v[i+1] += v[i]/10; 
		v[i] %= 10; 
	}
	return v;  
}

// note that the numbers are entered in reverse order
// e.g. 123*456 is stored as {3,2,1}*{6,5,4} in vector form  
vector<int> multiply(vector<int>& a, vector<int>& b){
	vector<int> c(a.size()+b.size()+1,0); 
	for (int i = 0; i < a.size(); i++){
		for (int j = 0; j < b.size(); j++){
			c[i+j] += a[i]*b[j];  
		}
	}
	normalize(c); 
	return c; 
}

void printVec(vector<int>& a){
	for (int i = 0; i < a.size(); i++){
		cout << a[i]; 
	}
	cout << endl; 
}

int findSum(vector<int>&a){
	int sum = 0;  
	for (int i = 0; i < a.size(); i++){
		sum += a[i]; 
	}
	return sum; 
}

int main(){
	vector<int> a,b; 
	a.push_back(1); 
	for (int i = 1; i <= 100; i++){
		string s = intToString(i); 
		reverse(s.begin(),s.end()); 
		for (int j = 0; j < s.size(); j++){
			b.push_back(s[j]-'0'); 
		}
		a = multiply(a,b); 
		b.clear();
	}	
	int ans = findSum(a); 
	cout << ans << endl; 
	return 0; 
}
