/*
Problem Link: https://algospot.com/judge/problem/read/NUMB3RS
-두나발 박사는 검문을 피해 산으로만 이동. 
-두나발 박사는 교도소 탈출 당일 교도소와 인접한 마을 하나로 도망쳐 은신한다. 
-두나발 박사는 수색을 피하기 위해 매일 인접한 마을로 움직여 은신한다. 

q부터 경로를 만들어 나가면 문제가 수월해진다. 다음과 같은 점화식을 이용한다. 
search(here,days) = 탈옥 후 days일째에 두나발 박사가 here번 마을에 숨어 있을 확률. 
search()는 전날 박사가 숨어 있는 곳이 어디일지를 결정해가면서 각 사건의 확률을 계산합니다. 이때 박사가 전날 there에 있다가 
오늘 here로 올 확률은 search(there,days-1)에 1/adj(there)를 곱한 것입니다. 
*/

#include <iostream>
#include <cstdlib> 
#include <cmath> 
#include <cstdio> 
using namespace std;

int c,n,d,p,t,q;  
// c: no. of test cases 
// n: no. of villages 
// d: no. of days passed since escape 
// p: the village that contains the prison 
// t: no. of villages to calculate the probabilty. 
// q: the village no. that we need to calculate the probability for. 
double cache[51][101]; 

void init(){
	for (int i = 0; i < 51; i++){
		for (int j = 0; j < 101; j++){
			cache[i][j] = -1.0; 
		}
	}
}

// connected[i][j] = 마을 i,j가 연결되어 있는지 여부. 
// deg[i] = 마을 i와 연결된 마을의 갯수  
int connected[51][51], deg[51]; 
double search(int here, int days){
	// 기저 0일째:  
	if (days == 0) return (here == p?1.0:0.0); 
	// memoization 
	double& ret = cache[here][days]; 
	if (ret != -1.0) return ret; 
	ret = 0.0;  
	for (int there = 0; there < n; there++){
		if (connected[here][there]){
			ret += search(there,days-1)*1.0/deg[there];  
		}
	}
	return ret; 
} 


int main(){
	cin >> c; 
	for (int i = 0; i < c; i++){
		cin >> n >> d >> p; 
		// get information for connected and deg.
		for (int j = 0; j < n; j++){
			deg[j] = 0; 
			for (int k = 0; k < n; k++){
				cin >> connected[j][k]; 
				deg[j] += connected[j][k]; 
			}
		}
		init(); 
		// get information for villages we have to calculate the probabilty of. 
		cin >> t; 
		for (int j = 0; j < t; j++){
			cin >> q;  
			double ans = search(q,d);
			printf("%.10lf ",ans); 
		}
		printf("\n");
	}
	return 0; 
}
