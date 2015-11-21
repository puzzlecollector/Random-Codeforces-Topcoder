/*
Problem Link: https://algospot.com/judge/problem/read/QUANTIZE
점화식 quantize(from,parts) = min(sigma_{size = 1...n-from}[minError(from,from+size-1)+quantize(from+size,parts-1)]) 
을 이용한다. quantize(from,parts)는 최소 오류 제곱 합을 반환하는 함수고, minError(a,b)는 구간 a번째 숫자부터 b번째 숫자까지를 하나의 수로 
표현했을때 최소 오류를 반환합니다. 
*/
#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <cmath> 
#include <cstring> 
using namespace std; 

const int INF = 987654321;  
// A[]:  양자화해야할 수열, 정렬해야한다. 
// pSum[]: A[]의 부분합 저장. pSum[i]는 A[0]...A[i]의 합. 
// pSqSum[]:  A[]의 제곱의 부분합을 저장한다. pSqSum[i]는 A[0]^2...A[i]^2의 합. 
int c,n,parts; 
int A[101],pSum[101],pSqSum[101]; 
// A를 정렬하고, 각 부분합 계산
void precalc(){
	sort(A,A+n); 
	pSum[0] = A[0]; 
	pSqSum[0] = A[0]*A[0];  
	for (int i = 1; i < n; i++){
		pSum[i] = pSum[i-1] + A[i]; 
		pSqSum[i] = pSqSum[i-1] + A[i]*A[i]; 
	}
}
// A[lo]...A[hi]의 구간을 하나의 숫자로 표현할 때 최소 오차합을 계산한다. 
int minError(int lo, int hi){
	// 부분합을 이용해 A[lo]...A[hi]까지의 합을 구한다. 
	int sum = pSum[hi]-(lo == 0?0:pSum[lo-1]); 
	int sqSum = pSqSum[hi] - (lo == 0?0:pSqSum[lo-1]); 
	// 평균을 반올림한 값들로 이 수들을 표현한다.  
	int m = int(0.5 + (double)sum/(hi-lo+1));  
	int ret = sqSum - 2*m*sum + m*m*(hi-lo+1); 
	return ret;  
}

int cache[101][11]; 
int quantize(int from, int parts){
	// 기저: 모든 수를 다 양자화 했을때 
	if (from == n) return 0; 
	// 기저: 숫자는 남았는데 더 묶을 수 없을때 INF 반환. 
	if (parts == 0) return INF; 
	int& ret = cache[from][parts]; 
	if (ret != -1) return ret; 
	ret = INF; 
	// 조각의 길이를 변환시키며 최솟값을 찾는다. 
	for (int partSize = 1; from + partSize <= n; partSize++){
		ret = min(ret,minError(from,from+partSize-1)+quantize(from+partSize,parts-1));  
	}
	return ret;  
}

int main(){
	cin >> c; 
	for (int i = 0; i < c; i++){
		memset(cache,-1,sizeof(cache)); 
		cin >> n >> parts; 
		for (int j = 0; j < n; j++){
			cin >> A[j];  
		}
		precalc(); 
		int ans = quantize(0,parts);  
		cout << ans << endl; 
	} 
	return 0; 
}
