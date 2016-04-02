#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <set> 
#include <vector> 
using namespace std; 

int main(){
	set<int> s; 
	vector<int> ans; 
	int n,m,num;  
	cin >> n >> m;  
	for (int i = 1; i <= n; i++){
		cin >> num; 
		s.insert(num);  
	}
	for (int i = 1;; i++){
		if (s.count(i)) continue;  
		if (m >= i){
			ans.push_back(i); 
			m -= i; 
		}else{
			break; 
		}
	}
	cout << ans.size() << endl; 
	for (int i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";  
	}
	cout << endl; 
	return 0; 
}
