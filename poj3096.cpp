#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int x[1005]; 
int solve(int R,int n){
	int cnt = 0; 
	int i = 0;  
	while (i < n){
		int s = x[i++]; 
		while (i < n && x[i] <= s+R) i++; 
		int p = x[i-1];  
		cout << "p = " << p << endl; 
		while (i < n && x[i] <= p+R) i++; 
		cnt++;  
	}
	return cnt; 
}
int main(){
	while (1){
		int R,n; 
		cin >> R >> n; 
		if (R == -1 && n == -1) break; 
		for (int i = 0; i < n; i++){
			cin >> x[i]; 
		}
		sort(x,x+n); 
		int ans = solve(R,n); 
		cout << ans << endl; 
	}
	return 0;  
}
