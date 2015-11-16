/*
Problem link: https://algospot.com/judge/problem/read/WILDCARD 
와일드카드 패턴과 문자열의 길이가 모두 n이라고 할때, 부분문제의 최대 갯수는 n^2이고, 
matchMemoized() 는 한번 호출될때마다 최대 n번의 재귀호출을 하기 때문에 전체 시간복잡도는 
O(n^3). 
*/

#include <iostream>
#include <string> 
#include <vector> 
#include <algorithm> 
#include <cstring> 
using namespace std; 

string W,S; // W = wildcard, S = string. 
int cache[101][101];  
bool matchMemoized(int w, int s){
	if (w == W.length()){
		return s == S.length(); 
	}
	int& ret = cache[w][s];  
	if (ret != -1) return ret; 
	if (s == S.length()){
		// 문자열의 끝에 도달했을때  
		// 와일드카드의 남은 문자가 모두 *이면 대응 성공.
		if (W[w] == '*'){
			return ret = matchMemoized(w+1,s);  
		}
	}else if (W[w] == '?' || (W[w] == S[s])){
		// w와 s를 한칸 앞으로 움직인다. 
		return ret = matchMemoized(w+1,s+1);  
	}else if (W[w] == '*'){
		// *에 몇 글자를 대응해야 할지 재귀호출로 확인한다. 
		return ret = matchMemoized(w+1,s) || matchMemoized(w,s+1);  
	}
	// 이외의 경우 모두 실패 
	return ret = false;  
} 

int main(){
	int t; 
	cin >> t; 
	for (int i = 0; i < t; i++){
		vector<string> v;  
		cin >> W; 
		int n; 
		cin >> n; 
		for (int j = 0; j < n; j++){
			memset(cache,-1,sizeof(cache)); 
			cin >> S;  
			if (matchMemoized(0,0)){
				v.push_back(S);  
			}
		}
		sort(v.begin(),v.end());  
		for (vector<string>::size_type j = 0; j < v.size(); j++){
			cout << v[j] << endl;
		}
	}
	return 0; 
}
