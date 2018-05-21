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
	for (int j = 1; j <= 1000000; j *= 10){
		ans *= (s[j-1]-'0'); 
	} 
	cout << ans << endl; 
	return 0; 
}
