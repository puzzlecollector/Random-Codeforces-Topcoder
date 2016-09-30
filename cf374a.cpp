// codeforces: magicalcat

#include <iostream> 
#include <cstdlib> 
#include <cstdio> 
#include <algorithm> 
#include <string> 
#include <vector> 
using namespace std;  

int main(){
	int n; 
	cin >> n; 
	string s; 
	cin >> s; 
	int cnt = 0;  
	vector<int> ans; 
	bool flag = false;  
	for (int i = 0; i < n; i++){
		if (s[i] == 'B'){
			flag = true;  
			++cnt;  
		}else if (s[i] == 'W'){
			if (flag){
				flag = false;  
				ans.push_back(cnt); 
				cnt = 0;  
			}
		}

		if(i == n-1 && flag){
			ans.push_back(cnt); 
		}
	}
	cout << ans.size() << endl; 
	if (ans.size() == 0) return 0; 
	for (int i = 0; i < ans.size(); i++){
		cout << ans[i] << " "; 
	}
	cout << endl; 
	return 0;  
}
