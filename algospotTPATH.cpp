#include <iostream> 
#include <cstdlib> 
#include <algorithm> 
#include <cstring> 
#include <vector> 
using namespace std; 

#define MAXV 2001
#define INF 987654321

struct edge{int to,cost;}; 
//vector<edge> adj[MAXV]; 
int V,M;

struct DisjointSet{
	vector<int> parent,rank; 
	DisjointSet(int n): parent(n),rank(n,1){
		for (int i = 0; i < n; i++){
			parent[i] = i; 
		}
	}
	int find(int u){
		if (u == parent[u]) return u; 
		return parent[u] = find(parent[u]); // path compression. 
	}
	void merge(int u,int v){
		u = find(u),v = find(v); 
		if (u == v) return;  
		if (rank[u] > rank[v]) swap(u,v); 
		parent[u] = v; 
		if (rank[u] == rank[v]) rank[v]++;  
	}
}; 

vector<int> weights; 
vector< pair<int,pair<int,int> > > edges; 

int minUpperKruskal(int low){
	DisjointSet sets(V); 
	for (int i = 0; i < edges.size(); i++){
		if (edges[i].first < weights[low]) continue; 
		sets.merge(edges[i].second.first,edges[i].second.second); 
		if (sets.find(0) == sets.find(V-1)) return edges[i].first;  
	}
	return INF;  
}

int minWeightDifference(){
	int ret = INF;  
	for (int i = 0; i < weights.size(); i++){
		ret = min(ret,minUpperKruskal(i)-weights[i]);  
	}
	return ret; 
}

int main(){
	int t; 
	cin >> t; 
	while (t--){
		/*for (int i = 0; i < MAXV; i++){
			adj[i].clear(); 
		}*/  
		weights.clear(); 
		edges.clear(); 
		cin >> V >> M; 
		for (int i = 0; i < M; i++){
			int a,b,c; 
			cin >> a >> b >> c; 
			weights.push_back(c); 
			/*edge e; 
			e.to = b, e.cost = c; 
			adj[a].push_back(e);  
			e.to = a; 
			adj[b].push_back(e); */  
			edges.push_back(make_pair(c,make_pair(a,b)));  
		}
		sort(edges.begin(),edges.end()); 
		sort(weights.begin(),weights.end());  
		cout << minWeightDifference() << endl; 
	}
	return 0; 
}
