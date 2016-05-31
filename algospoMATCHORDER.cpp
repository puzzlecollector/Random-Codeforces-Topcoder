#include <iostream> 
#include <cstdio> 
#include <vector> 
#include <set> 
#include <algorithm> 
using namespace std;  

int order(vector<int> &russian,vector<int> &korean){
	int n = russian.size(), wins = 0;  
	multiset<int> ratings(korean.begin(),korean.end()); 
	for (int rus = 0; rus < n; rus++){
		if (*ratings.rbegin() < russian[rus]){
			ratings.erase(ratings.begin()); 
		}else{
			//이길 수 있는 경우 선수 중 가장 레이팅이 낮은 선수와 경기시킨다. 
			ratings.erase(ratings.lower_bound(russian[rus]));   
			++wins; 
		}
	}
	return wins;  
}

int main(){
	int c; 
	cin >> c; 
	while (c--){
		vector<int> russian,korean; 
		int n,rating; 
		cin >> n; 
		for (int i = 0; i < n; i++){
			cin >> rating; 
			russian.push_back(rating); 
		}
		for (int i = 0; i < n; i++){
			cin >> rating; 
			korean.push_back(rating);  
		}
		int ans = order(russian,korean); 
		cout << ans << endl; 
	}
	return 0;  
}
