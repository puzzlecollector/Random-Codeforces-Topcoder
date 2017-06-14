// brute force. Takes a few seconds 
#include <iostream>
#include <map>
#include <set> 
#include <algorithm>
using namespace std; 
int digitLen(int x){
	if (x == 0) return 1; 
	int len = 0;  
	while (x){
		x /= 10; 
		len++; 
	}
	return len;  
}
bool chk(int i,int j,int k){
	map<int,int> mp; 
	while (i){
		mp[i%10]++;  
		i /= 10;  
	}
	while (j){
		mp[j%10]++;  
		j /= 10; 
	}
	while (k){
		mp[k%10]++; 
		k /= 10; 
	}
	for (int l = 1; l <= 9; l++){
		if (mp[l] != 1) return false; 
	}
	return true; 
}
int main(){
	// answer has to be 2 digit x 3 digits 
	long long ans = 0; 
	set<int> st;   
	for (int i = 1; i <= 9999; i++){
		for (int j = 1; j <= 9999; j++){
			int k = i*j;  
			if (digitLen(k) == 4 && chk(i,j,k)){
				st.insert(k); 
			}
		}
	}
	for (set<int>::iterator it = st.begin(); it != st.end(); it++){
		ans += (*it); 
	}
	cout << ans << endl; 
	return 0;  
}
