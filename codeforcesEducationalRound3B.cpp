// Problem Link: http://codeforces.com/contest/609/problem/B 
// this problem cannot be solved using double for loop and iterating all n inputs. 
// we have to take note of the number of times each genre appears and then add all 
// the pairwise multiplication of each occurence.  
#include <iostream> 
#include <cstdlib> 
#include <vector> 
#include <algorithm> 
using namespace std;  

int cnt[11]; 
int n,m,a; 

int main(){
	cin >> n >> m; 
	for (int i = 0; i < n; i++){
		cin >> a; 
		cnt[a]++;  
	}
	int sum = 0; 
	for (int i = 0; i < m+1; i++){
		for (int j = i+1; j < m+1; j++){
			sum += cnt[i]*cnt[j];  
		}
	}
	cout << sum << endl; 
	return 0; 
}

// by Minsuk Kim (lukekms)
