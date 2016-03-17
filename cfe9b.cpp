// Alice, Bob and two teams 
#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <string> 
using namespace std; 

int p[500001];  
char s[500001];  

int main(){
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> p[i];  
	}
	for (int i = 0; i < n; i++){
		cin >> s[i];  
	}
	long long ans = 0; 
	for (int i = 65; i <= 66; i++){ // do twice to see effects for suffix and prefix. 
		long long sum = 0; 
		for (int j = 0; j < n; j++){
			if (s[j] == char(i)) sum += p[j];  
		}
		for (int j = 0; j < n; j++){
			if (s[j] == char(i)) sum -= p[j]; 
			else sum += p[j];  
			ans = max(ans,sum); 
		}
	}
	cout << ans << endl; 
	return 0; 
}
