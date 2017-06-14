#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <sstream> 
using namespace std; 
string toString(int x){
	stringstream ss; 
	ss << x; 
	return ss.str(); 
}
bool isPalindrome(string s){
	for (int i = 0; i < s.size()/2; i++){
		if (s[i] != s[s.size()-i-1]){
			return false;  
		}
	}
	return true;  
}
string toBinary(int x){
	string t;  
	while (x){
		t += (x%2 == 1 ? "1" : "0");  
		x /= 2;  
	}
	reverse(t.begin(),t.end()); 
	return t;  
}
int main(){
	int ans = 0;  
	for (int i = 1; i < 1000000; i++){
		string tmp = toString(i);  
		if (isPalindrome(tmp) && isPalindrome(toBinary(i))){
			ans += i;  
		}
	}
	cout << ans << endl; 
	return 0;  
}		
