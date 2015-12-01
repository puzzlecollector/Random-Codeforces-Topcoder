/*
Problem Link: https://algospot.com/judge/problem/read/MORSE
문자열 S에다가 n개의 - 와 m개의 o를 사용하여 신호를 만들때, 총 n+mCm 개의 경우의 수가 있다. 
이것을 이용해서 처음 k개를 건너뛸 수 있도록 한다. 
이항개수를 계산해야하기 때문에, 시간복잡도는 O(mn). 
*/
#include <iostream> 
#include <cstdlib> 
#include <string> 
#include <cstring> 
#include <algorithm> 
using namespace std; 

int c,n,m,k,skip;  
int bino[201][201];
const int M = 1000000000+100; 

void calcBino(){
	memset(bino,0,sizeof(bino));  
	for (int i = 0; i <= 200; i++){
		bino[i][0] = bino[i][i] = 1; 
		for (int j = 1; j < i; j++){
			bino[i][j] = min(M,bino[i-1][j-1]+bino[i-1][j]);  
		}
	}
}

void generate(int n, int m, string s){
	if (skip < 0){
		return; 
	}
	if (n == 0 && m == 0){
		cout << s << endl; 
		--skip; 
		return; 
	}
	if (bino[n+m][n] <= skip){
		skip -= bino[n+m][n];  
		return; 
	}
	if (n > 0) generate(n-1,m,s+"-");  
	if (m > 0) generate(n,m-1,s+"o"); 
}

int main(){
	calcBino(); 
	cin >> c;
	for (int i = 0; i < c; i++){
		cin >> n >> m >> k; 
		skip = k-1;  
		string s = "";
		generate(n,m,s); 
	}
	return 0; 
}
