#include <iostream> 
#include <cstdlib> 
#include <cstdio> 
#include <vector> 
using namespace std; 

#define MAXV 111 

vector<int> G[MAXV]; 
int visited[MAXV];  

void dfs(int s){
	printf("%d ",s);  
	visited[s] = 1; 
	for (int i = 0; i < G[s].size(); i++){
		if (!visited[G[s][i]]){
			visited[G[s][i]] = 1; 
			dfs(G[s][i]); 
		}
	}
	return; 
}

int main(){
	int V,E,a,b; 
	scanf("%d %d",&V,&E); 
	for (int i = 0; i < E; i++){
		scanf("%d %d",&a,&b); 
		G[a].push_back(b); 
		G[b].push_back(a); 
	}
	dfs(1); 
	printf("\n"); 
	return 0; 
}
