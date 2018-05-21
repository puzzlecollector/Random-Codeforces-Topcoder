#include <iostream>
#include <cstdlib> 
#include <sstream> 
using namespace std; 
string toStr(int x){
	stringstream ss;  
	ss << x; 
	return ss.str(); 
}
int main(){
	string s;
	int i = 1;  
	while (s.size() <= 1000000){
		s += toStr(i); 
		i++; 
	}
	int ans = 1; 
	for (int i = 1; i <= 1000000; i *= 10){
		ans *= (s[i-1]-'0'); 
	} 
	cout << ans << endl; 
	return 0; 
}
