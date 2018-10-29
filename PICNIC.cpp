// given M pairs of friends, find how many ways we can pair the friends 
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;  
int n,m; 
bool areFriends[11][11];  
int solve(bool taken[]){
	int firstStudent = -1;  
	for (int i = 0; i < n; i++){
		if (!taken[i]){
			firstStudent = i; 
			break; 
		}
	}
	if (firstStudent == -1){
		return 1; 
	}
	int ret = 0;  
	for (int i = firstStudent+1; i < n; i++){
		if (!taken[i] && areFriends[firstStudent][i]){
			taken[firstStudent] = taken[i] = true; 
			ret += solve(taken);  
			taken[firstStudent] = taken[i] = false; 
		}
	}
	return ret; 
}
int main(){
	int t; 
	cin >> t; 
	while (t--){
		bool taken[10];
		cin >> n >> m;    
		memset(areFriends,false,sizeof(areFriends)); 
		memset(taken,false,sizeof(taken)); 
		for (int j = 0; j < m; j++){
			int a,b; 
			cin >> a >> b;  
			areFriends[a][b] = areFriends[b][a] = true; 
		}
		cout << solve(taken) << endl; 
	}
	return 0; 
}
