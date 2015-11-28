/*
Problem Link: https://algospot.com/judge/problem/read/PACKING
This is a variation of the classic 0/1 knapsack problem 
배낭문제의 변형된 버전이다. 
*/
#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <vector>
#include <string>  
#include <cstring> 
using namespace std; 

int c,n; 
int volume[100],need[100]; 
// 캐리어에 남은 용량이 capacity일때, item 이후의 물건들을 
// 담아 얻을 수 있는 최대 절박도를 반환한다. 
int cache[1001][100];  
string name[100]; 
int pack(int capacity, int item){
	if (item == n) return 0; 
	int& ret = cache[capacity][item]; 
	if (ret != -1) return ret; 
	// 물건을 담지 않을 경우 
	ret = pack(capacity,item+1);
	// 물건을 담는 경우 
	if (capacity >= volume[item]){
		ret = max(ret,pack(capacity-volume[item],item+1)+need[item]); 
	}
	return ret;  
}	

void reconstruct(int capacity, int item, vector<string>& picked){
	if (item == n) return; 
	if (pack(capacity,item) == pack(capacity,item+1)){
		reconstruct(capacity,item+1,picked); 
	}else{
		picked.push_back(name[item]);  
		reconstruct(capacity-volume[item],item+1,picked); 
	}
}

int main(){
	cin >> c; 
	for (int i = 0; i < c; i++){
		int capacity;  
		cin >> n >> capacity; 
		string objectName;  
		int vol, desp; 
		for (int j = 0; j < n; j++){
			cin >> objectName >> vol >> desp; 
			name[j] = objectName;  
			volume[j] = vol;  
			need[j] = desp; 
		}
		memset(cache,-1,sizeof(cache));  
		vector<string> picked;  
		int maxDesp = pack(capacity,0);
		reconstruct(capacity,0,picked);   
		cout << maxDesp << " " << picked.size() << endl;  
		for (int j = 0; j < picked.size(); j++){
			cout << picked[j] << endl; 
		} 
	}
	return 0;  
}
