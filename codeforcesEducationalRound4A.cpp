// Problem Link: http://codeforces.com/contest/612/problem/A
#include <iostream> 
#include <string> 
using namespace std;  

int main(){
	int n,p,q;  
	cin >> n >> p >> q; 
	string s; 
	cin >> s; 
	if (n%p == 0){
		cout << n/p << endl; 
		for (int i = 0; i < n; i += p){
			for (int j = i; j < i+p; j++){
				cout << s[j]; 
			}
			cout << endl; 
		}
	}else if (n%q == 0){
		cout << n/q << endl; 
		for (int i = 0; i < n; i += q){
			for (int j = i; j < i+q; j++){
				cout << s[j]; 
			}
			cout << endl; 
		}
	}else{
		int a=-1,b=-1;  
		for (int i = 1; i <= n/p; i++){
			for (int j = 1; j <= n/q; j++){
				if (n == i*p+j*q){
					a = i;  
					b = j; 
					break; 
				}
			}
		}
		if (a == -1 && b == -1) cout << -1 << endl; 
		else{
			cout << a+b << endl; 
			for (int i = 0; i < a*p; i += p){
				cout << s.substr(i,p) << endl; 
			}
			for (int i = a*p; i < s.size(); i += q){
				cout << s.substr(i,q) << endl; 
			}
		}	
	}
	return 0; 
}
