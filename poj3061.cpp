#include <iostream>
#include <cstdlib>
#include <cstring> 
#include <algorithm>
using namespace std; 
const int INF = 222222;
int a[100005]; 
int main(){
	int t; 
	cin >> t; 
	while (t--){
		memset(a,0,sizeof(a)); 
		int n,S; 
		cin >> n >> S;  
		for (int i = 0; i < n; i++){
			cin >> a[i]; 
		}
		int l = 0, r = 0, sum = 0, ans = INF;  
		while (l < n){
			while (r < n && sum <= S){
				sum += a[r]; 
				r++;  
			} 
			if (sum >= S) ans = min(ans,r-l); 
			sum -= a[l]; 
			l++; 
		}
		if (ans == INF) cout << 0 << endl; 
		else cout << ans << endl; 
	}
	return 0; 
}
