/*
Problem Link: https://algospot.com/judge/problem/read/DRAGON
드래곤 커브를 만드는 재귀 호출 알고리즘과, 이 알고리즘이 몇 글자를 출력할지 계산하는 
동적 계획법 알고리즘을 만듭니다. 

expand() 함수는 최대 n번 재귀호출되고, 한번 재귀호출될때 O(1) 시간이 걸린다 (최대 길이 5인 반복문) 
따라서 시간복잡도는 O(n). 
*/

#include <iostream> 
#include <cstdlib> 
#include <cassert> 
#include <string> 
#include <algorithm>  
using namespace std; 

int c,n,p,l;  
const int MAX = 1000000000+1;  
// length[i] = X나 Y를 i번 치환한 후의 길이. 
int length[51]; 
void precalc(){
	length[0] = 1;  
	for (int i = 1; i <= 50; i++){
		length[i] = min(MAX,length[i-1]*2 + 2); // overflow 방지차원 
	}
}

const string EXPAND_X = "X+YF"; 
const string EXPAND_Y = "FX-Y"; 
// dragonCurve를 generation 진화시킨 결과에서 skip번째 문자를 반환한다. 
char expand(const string& dragonCurve, int generations, int skip){
	if (generations == 0){
		assert(skip < dragonCurve.size());
		return dragonCurve[skip]; 
	}
	for (int i = 0; i < dragonCurve.size(); i++){
		// 문자열이 확장되는 경우. 
		if (dragonCurve[i] == 'X' || dragonCurve[i] == 'Y'){
			if (skip >= length[generations]){
				skip -= length[generations]; 
			}else if (dragonCurve[i] == 'X'){
				return expand(EXPAND_X,generations-1,skip); 
			}else{
				return expand(EXPAND_Y,generations-1,skip); 
			}
		}
		// 확장되진 않지만 건너뛰어야할 경우 
		else if (skip > 0){
			--skip; 
		}
		// 답을 찾은 경우  
		else{
			return dragonCurve[i]; 
		}
	}
	return '#'; // 이 줄은 실행되지 않는다. 
}

int main(){
	precalc(); 
	cin >> c; 
	for (int i = 0; i < c; i++){
		cin >> n >> p >> l; 
		string ans = ""; 
		for (int j = p; j < p+l; j++){
			ans += expand("FX",n,j-1); 
		}
		cout << ans << endl; 
	}
	return 0; 
}
