// Problem Link: http://codeforces.com/contest/610/problem/C
#include <iostream> 
#include <cstdlib> 
#include <cstring> 
#include <algorithm> 
#include <cstdio> 
using namespace std; 

int n; 
int cnt = 0; 
char s[1<<10]; 
int two2n; 
char pl = '+'; 
char st = '*'; 

void solve(int curr){
	if (curr == two2n){
		printf("%s\n",s+1); 
		return; 
	}
	int next = 2*curr; 
	for (int i = curr+1; i <= next; i++){
		s[i] = s[i-curr]; 
	}
	solve(next); 
	for (int i = curr+1; i <= next; i++){
		s[i] = (s[i-curr] == pl ? st:pl); 
	}
	solve(next); 
}

int main(){
	cin >> n; 
	two2n = 1 << n; 
	s[1] = pl; 
	s[two2n+1] = '\0'; 
	solve(1); 
	return 0; 
}
