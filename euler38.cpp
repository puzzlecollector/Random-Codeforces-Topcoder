#include <iostream>
#include <cstdlib>
#include <sstream> 
#include <algorithm>
#include <map> 
using namespace std; 
typedef long long ll; 
int toInt(string s){
	istringstream iss (s);
	int n; 
	iss >> n; 
	return n;  
}
ll len(ll x){
	if (x == 0) return 1; 
	ll cnt = 0; 
	while (x){
		cnt++; 
		x /= 10; 
	}
	return cnt; 
}
void add(string &t,ll x){
	string s; 
	while (x){
		s += char(x%10 + '0'); 
		x /= 10; 
	}
	reverse(s.begin(),s.end()); 
	t += s;  
}
int main(){
	int ans = 0; 
	for (ll i = 1;;i++){
		if (len(i)+len(i*2LL) > 9LL){
			break; 
		}
		ll j = 1; 
		string t = ""; 
		while (t.size() < 9){
			ll concat = i*j;  
			add(t,concat);
			j++;  
		}
		//cout << t << endl; 
		if (t.size() > 9) continue; 
		map<char,int> mp;
		for (int k = 0; k < t.size(); k++){
			mp[t[k]]++; 
		}
		bool passed = true;
		for (char k = '1'; k <= '9'; k++){
			if (!mp.count(k)){
				passed = false; 
				break; 
			}
		}
		if (passed){
			ans = max(ans,toInt(t));  
		}
	}
	cout << ans << endl;
	return 0; 
}
