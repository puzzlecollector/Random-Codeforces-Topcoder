/*
Problem Link: https://algospot.com/judge/problem/read/KLIS#c11702
k번째 LIS구하기 문제 
종만북과 달리 k값의 범위가 아마 더 크다 (32비트 정수에 담을 수 있다고만했지 ≤ 2*10^9 라고하진 않았다...)
따라서 cacheCnt를 long long을 담는 배열로 바꿈!! 
*/
#include <iostream>
#include <cstdlib> 
#include <vector> 
#include <algorithm> 
#include <climits> 
#include <utility> 
#include <cstring> // for memset()
using namespace std; 

typedef long long ll; 

const int MAX = 2000000000+1;  
int c,n,k; 
ll cacheLen[501],cacheCnt[501],S[501]; 
// S[start]에서 시작하는 증가 부분 수열중, 최대 길이를 반환합니다. 
ll lis(int start){
	// memoization 
	ll& ret = cacheLen[start+1]; 
	if (ret != -1) return ret; 
	ret = 1; 
	for (int next = start+1; next < n; next++){
		if (start == -1 || S[start] < S[next]){
			ret = max<ll>(ret,lis(next)+1); 
		}
	}
	return ret; 
}

// S[start]에서 시작하는 최대 증가 부분 수열의 수를 반환한다. 
ll count(int start){
	// 기저: LIS의 길이가 1인 경우 
	if (lis(start) == 1) return 1; 
	// memoization 
	ll& ret = cacheCnt[start+1]; 
	if (ret != -1) return ret; 
	ret = 0; 
	for (int next = start+1; next < n; next++){
		if ((start == -1 || S[start] < S[next]) && lis(start) == lis(next)+1){
			ret = min<ll>(MAX,ret + count(next));  // overflow방지차원에서 MAX와 비교한다. 
		}
	}
	return ret; 
}

// S[start]에서 시작하는 LIS중 사전순으로 skip개 건너뛴 수열을 lis에 저장한다. 
void reconstruct(int start, int skip, vector<ll>& list){
	// 1. S[start]는 항상 LIS에 포함. 
	if (start != -1) list.push_back(S[start]); 
	// 2. 뒤에 올 수 있는 숫자들과 위치의 목록을 만든다. 
	// (숫자, 숫자의 위치)의 목록이 된다. 
	vector< pair<ll,ll> > followers; 
	for (int next = start+1; next < n; next++){
		if ((start == -1 || S[start] < S[next]) && lis(start) == lis(next)+1){
			followers.push_back(make_pair(S[next],next));  
		}
	}
	sort(followers.begin(),followers.end());  
	// 3. k번째 LIS의 다음 숫자를 찾는다. 
	for (int i = 0; i < followers.size(); i++){
		// 이 숫자를 뒤에 이어서 만들 수 있는 LIS의 개수를 본다. 
		int idx = followers[i].second; 
		int cnt = count(idx);  
		if (cnt <= skip){
			skip -= cnt;  
		}else{
			// 다음 숫자는 S[idx]임을 알았으니, 나머지 lis를 재귀호출로 만들어준다. 
			reconstruct(idx,skip,list); 
			break; 
		}
	}
}

int main(){
	cin >> c; 
	for (int i = 0; i < c; i++){
		cin >> n >> k;  
		memset(cacheLen,-1,sizeof(cacheLen)); 
		memset(cacheCnt,-1,sizeof(cacheCnt)); 
		for (int j = 0; j < n; j++){
			cin >> S[j]; 
		}
		vector<ll> answerList;
		// k-1개 건너뛰고 k번째 수열을 찾을 수 있기 때문!!   
		reconstruct(-1,k-1,answerList);  
		cout << answerList.size() << endl; 
		// print kth LIS
		for (int j = 0; j < answerList.size(); j++){
			cout << answerList[j] << " "; 
		}
		cout << endl; 
	}
	return 0; 
}
