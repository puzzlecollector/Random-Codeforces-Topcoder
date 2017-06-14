#include <iostream>
#include <algorithm>
#include <cmath> 
using namespace std; 
bool isPrime(int x){
	for (int i = 2; i*i <= x; i++){
		if (x%i == 0) return false; 
	}
	return x != 1;  
}
bool chk(int x){
	// truncate from right to left 
	int tmp = x;  
	while (tmp){
		if (!isPrime(tmp)) return false;  
		tmp /= 10;  
	}
	// truncate from left to right
	int len = 0;  
	tmp = x; 
	while (tmp){
		len++; 
		tmp /= 10;  
	}
	tmp = x;  
	for (int i = len-1; i >= 0; i--){
		if (!isPrime(tmp)) return false;  
		tmp = tmp - (tmp/(int)pow(10,i))*pow(10,i);  
	}
	return true;  
}
int main(){
	int cnt = 0, ans = 0; 
	for (int i = 11;;i += 2){
		if (cnt == 11) break; 
		if (chk(i)){
			cnt++;  
			ans += i;  
		}
	}
	cout << ans << endl; 
	return 0;   
}
