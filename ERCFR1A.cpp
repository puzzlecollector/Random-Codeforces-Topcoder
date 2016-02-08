// http://codeforces.com/contest/598/problem/A 
// Educational Codeforce Round 1A
#include <iostream>
#include <cstdlib> 
#include <cmath> 
using namespace std; 

typedef long long ll; 

int main(){
	int t; 
	cin >> t; 
	for (int i = 0; i < t; i++){
		ll n; 
		cin >> n; 
		ll ans = (n)*(n+1)/2;  
		ll two = 1; 
		while (two <= n){
			ans -= two*2;  
			two *= 2; 
		}
		cout << ans << endl; 
	}
	return 0; 
}
