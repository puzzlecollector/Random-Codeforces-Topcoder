#include <iostream> 
#include <cstdlib> 
#include <algorithm> 
#include <vector> 
#include <queue> 
using namespace std;  

#define MAXV 1001 
#define INF 987654321 

typedef pair<int,int> P; 

struct edge{int to,cost;};  

vector<edge> G[MAXV]; 
int d[MAXV]; 
int V,E,m,n;  

void dijkstra(int s){
	// s: starting node; 
	fill(d,d+V+1,INF);  
	d[s] = 0; 
	priority_queue< P,vector<P>,greater<P> > pq; 
	pq.push(make_pair(d[s],s)); 
	while (!pq.empty()){
		P p = pq.top(); pq.pop();  
		int v = p.second; 
		if (d[v] < p.first) continue; 
		for (int i = 0; i < G[v].size(); i++){
			edge e = G[v][i];  
			if (d[e.to] > d[v]+e.cost){
				d[e.to] = d[v]+e.cost;  
				pq.push(make_pair(d[e.to],e.to));  
			}
		}
	}
}

int main(){
	int t; 
	cin >> t;  
	while (t--){
		for (int i = 0; i < MAXV; i++){
			G[i].clear(); 
		}
		cin >> V >> E >> n >> m; 
		for (int i = 0; i < E; i++){
			int a,b,c;  
			cin >> a >> b >> c;  
			edge e; 
			e.to = b, e.cost = c; 
			G[a].push_back(e);  
			e.to = a, e.cost = c;  
			G[b].push_back(e);  
		}		
		vector<int> fire,station; 
		for (int i = 0; i < n; i++){
			int node; 
			cin >> node; 
			fire.push_back(node); 
		}
		for (int i = 0; i < m; i++){
			int node;  
			cin >> node; 
			station.push_back(node); 
		}
		// let node 0 connect to fire stations with outgoing cost 0. 
		for (int i = 0; i < m; i++){
			edge e;  
			e.to = station[i]; e.cost = 0; 
			G[0].push_back(e);  
			e.to = 0; e.cost = 0; 
			G[station[i]].push_back(e);  
		}
		dijkstra(0); 
		int sum = 0;   
		for (int i = 0; i < n; i++){
			sum += d[fire[i]]; 
		}	
		cout << sum << endl; 
	}	
	return 0;  
}
