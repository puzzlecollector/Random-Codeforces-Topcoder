// Problem Link: http://codeforces.com/contest/609/problem/C
// Referred to I_love_Tanya_Romanova's code
#include <iostream> 
#include <cstdlib> 
#include <cstring> 
#include <algorithm> 
#include <string> 
#include <vector> 
using namespace std; 

#define MAX 100001

int a[MAX], need[MAX]; 
int main(){
	int n,full,rem,ans=0,sum=0; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
		sum +=  a[i];  
	}
	sort(a,a+n);  
	full = sum/n; 
	rem = sum%n; 
	for (int i = 0; i < n; i++){
		need[i] = full;  
	}
	for (int i = n-1; i >= 0; i--){
		if (rem == 0){
			continue; 
		}
		need[i]++; 
		rem--;  
	}
	for (int i = 0; i < n; i++){
		if (a[i] > need[i]){
			ans += a[i]-need[i];  
		}
	}
	cout << ans << endl; 
	return 0; 
}
