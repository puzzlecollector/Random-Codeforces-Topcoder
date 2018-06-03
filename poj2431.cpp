// slightly modified 
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <queue> 
using namespace std; 
const int MAXN = 10005;  
int A[MAXN+1];
int B[MAXN+1];  
int N,L,P; 
int main(){
	cin >> N >> L >> P;  
	for (int i = 0; i < N; i++){
		cin >> A[i]; 
	}
	for (int i = 0; i < N; i++){
		cin >> B[i];  
	}
	int ans = 0, pos = 0, tank = P; 
	priority_queue<int, vector<int>, less<int> > pq; 
	for (int i = 0; i < N; i++){
		int d = A[i]-pos; 
		while (tank-d < 0){
			if (pq.empty()){
				cout << -1 << endl; 
				return 0; 
			}
			tank += pq.top(); 
			pq.pop();  
			ans++; 
		}
		tank -= d; 
		pos = A[i]; 
		pq.push(B[i]); 
	}
	cout << ans << endl;
	return 0; 
}
