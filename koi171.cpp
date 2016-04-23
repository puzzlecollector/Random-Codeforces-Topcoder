// http://koistudy.net/?mid=prob_page&NO=171
#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <vector> 
#include <queue> 
using namespace std; 
#define MAXV 111 

vector<int> G[MAXV]; 
int visited[MAXV]; 

void bfs(int s){
	queue<int> que; 
	que.push(s);  
	visited[s] = 1; 
	while (!que.empty()){
		int v = que.front(); que.pop(); 
		printf("%d ",v); 
		for (int i = 0; i < G[v].size(); i++){
			if (!visited[G[v][i]]){
				visited[G[v][i]] = 1;  
				que.push(G[v][i]);  
			}
		}
	}
}

int main(){
	int V,E,a,b; 
	scanf("%d %d",&V,&E);  
	for (int i = 0; i < E; i++){
		scanf("%d %d",&a,&b);  
		G[a].push_back(b);  
		G[b].push_back(a);  
	}
	bfs(1);  
	printf("\n"); 
	return 0; 
}
