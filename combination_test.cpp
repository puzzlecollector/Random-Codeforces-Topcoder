#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
typedef long long ll;  
ll bino[30][30];
void calc(){
	for (int i = 0; i < 30; i++){
		for (int j = 0; j < 30; j++){
			if (i == 0 || j == 0 || i == j) bino[i][j] = 1LL; 
			else bino[i][j] = bino[i-1][j-1]+bino[i-1][j];   
		}
	}
} 
int main(){
	calc(); 
	for (int i = 0; i <= 8; i++){
		cout << i << " " << 8-i << " " << bino[20][i] << " " << bino[20][8-i] << " " << bino[20][i]*bino[20][8-i] << endl; 
	}
	return 0; 
}
