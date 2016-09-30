#include <iostream> 
#include <cstdlib> 
#include <cstdio> 
#include <algorithm> 
#include <string> 
#include <vector> 
#include <map> 
using namespace std;  

int main(){
	int n,k;  
	cin >> n >> k;  
	map<int,int> mp;  
	for (int i = 0; i < n; i++){
		string s; 
		cin >> s; 
		mp[(int)s.size()]++;  
	}
	string password; 
	cin >> password;  
	int best = 0, worst = 0;  
	for (map<int,int>::iterator it = mp.begin(); it != mp.end(); it++){
		if (it->first >= password.size()) break; 
		best += it->second;  
	}
	best += (best/k)*5;  
	for (map<int,int>::iterator it = mp.begin(); it != mp.end(); it++){
		if (it->first > password.size()) break; 
		worst += it->second;  
	}
	--worst; worst += (worst/k)*5;  
	cout << best + 1 << " " << worst + 1 << endl; 
	return 0;  
}	
