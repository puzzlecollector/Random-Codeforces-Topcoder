/*
Problem Link: https://www.acmicpc.net/problem/1992
전부 검사해주면서 숫자가 모두 같으면 출력하고 다르면 재귀호출한다. 
재귀의 시작과 끝에 가로를 출력한다. 
Yukariko님의 소스 참고함: https://github.com/Yukariko/acm/blob/master/problem/1992/test.c
*/

#include <iostream> 
#include <cstdlib> 
#include <cstring> 
#include <cstdio>  
#include <cstdio> 
#include <vector> 
#include <algorithm> 
using namespace std; 

char grid[65][65];  

void compress(int y, int x, int size){
	int i,j; 
	char chk = grid[y][x];  
	for (i = 0; i < size; i++){
		for (j = 0; j < size; j++){
			if (grid[y+i][x+j] != chk) break; 
		}
		if (j != size) break; 
	}
	if (i == size){
		cout << chk; 
	}else{
		cout << "("; 
		int half = size/2; 
		compress(y,x,half); 
		compress(y,x+half,half);  
		compress(y+half,x,half); 
		compress(y+half,x+half,half);  
		cout << ")";  
	}
}	


int main(){
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> grid[i][j]; 
		}
	}
	compress(0,0,n);  
	cout << endl; 
	return 0; 
}

