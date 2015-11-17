/*
Problem link: https://algospot.com/judge/problem/read/JLIS
탐욕법(greedy)으로 해결할 수 없다. 다음 점확식을 사용한다. 
jlis(indexA, indexB) = A[indexA]와 B[indexB]에서 시작하는 합친 증가 부분 수열의 최대 길이. 
jlis(indexA, indexB) = max(max(jlis(nextA,indexB)+1,jlis(indexA,nextB)+1)) 
*/ 
#include <iostream>
#include <cstdlib>
#include <climits> 
#include <cstring>
#include <algorithm> 
using namespace std; 

const long long NEGINF = numeric_limits<long long>::min(); 
int n,m,A[100],B[100]; 
int cache[101][101]; 

int jlis(int indexA, int indexB){
	// memoization 
	int& ret = cache[indexA+1][indexB+1];  
	if (ret != -1) return ret; 
	// A[indexA],B[indexB]가 존재하므로 답은 적어도 2개는 있다. 
	ret = 2; 
	long long a = (indexA == -1 ? NEGINF:A[indexA]);  
	long long b = (indexB == -1 ? NEGINF:B[indexB]);  
	long long maxElement = max(a,b); 
	// 다음 원소를 찾는다. 
	for (int nextA = indexA+1; nextA < n; nextA++){
		if (maxElement < A[nextA]){
			ret = max(ret,1+jlis(nextA,indexB)); 
		}
	}
	for (int nextB = indexB+1; nextB < m; nextB++){
		if (maxElement < B[nextB]){
			ret = max(ret,1+jlis(indexA,nextB)); 
		}
	}
	return ret; 
}

int main(){
	int t; 
	cin >> t; 
	for (int i = 0; i < t; i++){
		memset(cache,-1,sizeof(cache)); 
		cin >> n >> m; 
		for (int j = 0; j < n; j++){
			cin >> A[j]; 
		}
		for (int j = 0; j < m; j++){
			cin >> B[j]; 
		}
		int ans = jlis(-1,-1)-2; 
		cout << ans << endl; 
	}
	return 0; 
}
