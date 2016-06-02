#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <algorithm> 
#include <cmath> 
#include <string> 
#include <sstream> 
#include <vector> 
using namespace std; 

string input = "7  53 183 439 863 497 383 563  79 973 287  63 343 169 583 627 343 773 959 943 767 473 103 699 303 957 703 583 639 913 447 283 463  29  23 487 463 993 119 883 327 493 423 159 743 217 623   3 399 853 407 103 983  89 463 290 516 212 462 350 960 376 682 962 300 780 486 502 912 800 250 346 172 812 350 870 456 192 162 593 473 915  45 989 873 823 965 425 329 803 973 965 905 919 133 673 665 235 509 613 673 815 165 992 326 322 148 972 962 286 255 941 541 265 323 925 281 601  95 973 445 721  11 525 473  65 511 164 138 672  18 428 154 448 848 414 456 310 312 798 104 566 520 302 248 694 976 430 392 198 184 829 373 181 631 101 969 613 840 740 778 458 284 760 390 821 461 843 513  17 901 711 993 293 157 274  94 192 156 574 34 124 4 878 450 476 712 914 838 669 875 299 823 329 699 815 559 813 459 522 788 168 586 966 232 308 833 251 631 107 813 883 451 509 615 77 281 613 459 205 380 274 302 35 805"; 

int grid[15][15]; //  배열
int chooseRow[15];  // 각 행에서 가장 큰 수를 고른다. 
bool used[15];  // 그 행을 이용했는지 판별 
int maxval;  

int toInt(string s){ // string 객체에 있는 수를 배열에 담기 위해서 만듬 
	int n; 
	istringstream iss (s); 
	iss >> n; 
	return n; 
}

bool chk(int row,int sum){
	for (int i = row; i < 15; i++){
		sum += chooseRow[i]; 
	}
	return (sum > maxval ? true : false);  
}


void recur(int n,int sum){
	if (n == 15){
		maxval = max(maxval,sum); 
		return; 
	}
	if (!chk(n,sum)) return;  
	for (int i = 0; i < 15; i++){
		if (used[i]) continue; 
		else{
			used[i] = true; 
			recur(n+1,sum+grid[n][i]);  
			used[i] = false; 
		}
	}
}

int main(){
	// 우선 grid를 string 객체로 받은뒤에 int grid로 옮깁니다.  
	istringstream iss (input);  
	string word; 
	int i = 0,j = 0;  
	while (iss >> word){
		grid[i][j++] = toInt(word);
		if (j > 14){
			i++; 
			j = 0; 
		}
		if (j == 15){
			break; 
		} 
	}
	for (int i = 0; i < 15; i++){
		for (int j = 0; j < 15; j++){
			chooseRow[i] = max(chooseRow[i],grid[i][j]); 
		}
	}
	recur(0,0); 
	cout << maxval << endl; 
	return 0;  
}
