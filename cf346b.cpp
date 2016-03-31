#include <iostream>
#include <vector> 
#include <map> 
#include <algorithm> 
#include <cstdlib> 
#include <utility> 
using namespace std; 

typedef pair<int,string> P;  

bool cmp(P p1, P p2){
	return p1.first > p2.first;
}

int main(){
	int n,m; 
	map<int,vector<P> > mp;  // (region,(score,name)...)
	cin >> n >> m; 
	for (int i = 0; i < n; i++){
		string name; 
		int region,score; 
		cin >> name >> region >> score; 
		mp[region].push_back(make_pair(score,name));  
	}	
	for (int i = 1; i <= m; i++){
		sort(mp[i].begin(),mp[i].end(),cmp); 
	}
	for (int i = 1; i <= m; i++){
		if (mp[i].size() > 2 && mp[i][1].first == mp[i][2].first) cout << "?" << endl; 
		else cout << mp[i][0].second << " " << mp[i][1].second << endl; 
	}
	return 0; 
}
