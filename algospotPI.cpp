/*
Problem link: https://algospot.com/judge/problem/read/PI
Also a translation of a problem in Topcoder 
문제 배경: 
가끔 티비에는 원주율을 몇만 자리까지 외우는 사람들이 있다. 이들이 사용하는 방법중 하나는 
숫자를 몇 자리씩 끊어서 외우는 것이다. 이들은 숫자를 3~5자리까지 끊어서 외우는데 가능하면 55555나 123과 같이 
외우기 쉬운 조각들이 많이 등장하는 방법을 택하곤 한다. 
1. 모든 숫자가 같을때: 난이도 1 
2. 숫자가 1씩 단조증가하거나 단조 감소할때: 난이도 2 
3. 두개의 숫자가 번갈아가면 나타날때: 난이도 4
4. 숫자가 등차 수열을 이룰때: 난이도 5  
5. 이외의 모든 경우: 난이도 10 

이 문제를 풀기 위해서 다음과 같은 점화식을 이용한다. 
memorize(begin) = min_{L=3 to 5}(memorize(begin+L) + classify(N_{begin...L})) 
memorize 는 최소 난이도를 반환하는 함수, classify는 해당 조각의 난이도를 반환하는 함수, N_{begin...L} 은 
문자열 N[begin]에서 시작하는 길이 L인 부분 문자열이다. 

Time complexity: O(n)
*/

#include <iostream>
#include <algorithm> 
#include <cstdlib> 
#include <string> 
#include <cstring> 
using namespace std; 

const int INF = 987654321; 
string N; 
// N[a,b] 구간의 난이도를 반환한다. 
int classify(int a, int b){
	// 숫자 조각을 가져온다. 
	string M = N.substr(a,b-a+1);  
	// 모든 숫자가 같을때: 난이도 1
	if (M == string(M.size(),M[0])){
		return 1; 
	}
	// 등차수열인지 검사. 
	bool progressive = true; 
	for (int i = 0; i < M.size()-1; i++){
		if (M[i+1]-M[i] != M[1]-M[0]){
			progressive = false; 
			break;
		}
	}
	// 등차수열이고 공차가 1이면 난이도 2 
	if (progressive && abs(M[1]-M[0]) == 1){
		return 2; 
	}
	// 두 수가 번갈아 등장하는지 확인. 
	bool alternating = true; 
	for (int i = 0; i < M.size(); i++){
		if (M[i] != M[i%2]){
			alternating = false;
			break; 
		}
	}
	if (alternating) return 4; // 두개의 숫자가 번갈아가면 나타날때: 난이도 4
	if (progressive) return 5; // 숫자가 등차 수열을 이룰때: 난이도 5
	// 이외의 경우 
	return 10; 
}

int cache[10005];  
// N[begin...]를 외우는 방법중 난이도의 최소 합 출력. 
int memorize(int begin){
	// base case 
	if (begin == N.size()){
		return 0; 
	}
	// memoization 
	int& ret = cache[begin]; 
	if (ret != -1) return ret;  
	ret = INF; 
	for (int L = 3; L <= 5; L++){
		if (begin+L <= N.size()){
			ret = min(ret,memorize(begin+L)+classify(begin,begin+L-1)); 
		}
	}
	return ret; 
}

int main(){
	int t; 
	cin >> t; 
	for (int i = 0; i < t; i++){
		memset(cache,-1,sizeof(cache));  
		cin >> N;  
		int ans = memorize(0); 
		cout << ans << endl; 
	}
	return 0; 
}
