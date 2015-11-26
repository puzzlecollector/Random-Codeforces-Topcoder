/*
Problem Link: https://algospot.com/judge/problem/read/DRAWRECT
구현 문제 - 주어진 정보만으로 직사각형의 마지막 좌표를 추축한다.  
*/
#include <iostream> 
#include <cstdlib> 
#include <cstdio> 
using namespace std; 

int main(){
	int c,n; 
	cin >> c; 
	int x1,y1,x2,y2,x3,y3; 
	for (int i = 0; i < c; i++){
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3; 
		if (x1 == x2){
			cout << x3 << " "; 
			if (y1 != y3) cout << y1 << endl; 
			else if (y2 != y3) cout << y2 << endl; 
		}else if (x1 == x3){
			cout << x2 << " "; 
			if (y1 != y2) cout << y1 << endl; 
			else if (y3 != y2) cout << y3 << endl; 
		}else if (x2 == x3){
			cout << x1 << " "; 
			if (y2 != y1) cout << y2 << endl; 
			else if (y3 != y1) cout << y3 << endl; 
		}
	}
	return 0; 
}

