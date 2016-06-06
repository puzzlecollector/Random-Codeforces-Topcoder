#include <iostream> 
#include <cstdlib> 
#include <cstdio> 
#include <vector> 
#include <algorithm> 
using namespace std;  

#define MAXN 10001
int n,e[MAXN],m[MAXN];

int heat(){
	vector< pair<int,int> > order; 
	for (int i = 0; i < n; i++){
		order.push_back(make_pair(-e[i],i)); 
	}
	sort(order.begin(),order.end()); 
	int ret = 0, beginEat = 0;  
	for (int i = 0; i < n; i++){
		int box = order[i].second; 
		beginEat += m[box]; 
		ret = max(ret,e[box]+beginEat); 
	}
	return ret;  
}

int main(){
	int c; 
	scanf("%d",&c); 
	while (c--){
		scanf("%d",&n); 
		for (int i = 0; i < n; i++){
			scanf("%d",&m[i]); 
		}
		for (int i = 0; i < n; i++){
			scanf("%d",&e[i]); 
		}
		int ans = heat();  
		printf("%d\n",ans); 
	}
	return 0; 
}
