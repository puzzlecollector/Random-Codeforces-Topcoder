#include <iostream>
#include <cstdlib>
#include <vector> 
using namespace std; 
int gcd(int a,int b){
	if (b == 0) return a; 
	return gcd(b,a%b); 
}
int main(){
	vector< pair<int,int> > ans; 
	for(int i = 10; i <= 99; i++){
		for (int j = i+1; j <= 99; j++){
			// (first,first) are the same 
			int k = i/10, l = j/10;  
			if (k == l){
				if ((double)i/j == (double)(i%10)/(j%10)){
					if (k != 0 && l != 0){
						ans.push_back(make_pair(i,j)); 
					}
				}
			}
			// (first,second) are the same 
			k = i/10, l = j%10;  
			if (k == l){
				if ((double)i/j == (double)(i%10)/(j/10)){
					if (k != 0 && l != 0){
						ans.push_back(make_pair(i,j)); 
					}
				}
			}
			// (second,first) are the same 
			k = i%10, l = j/10; 
			if (k == l){
				if ((double)i/j == (double)(i/10)/(j%10)){
					if (k != 0 && l != 0){
						ans.push_back(make_pair(i,j)); 
					}
				}
			}
			// (second,second) are the same 
			k = i%10, l = j%10; 
			if (k == l){
				if ((double)i/j == (double)(i/10)/(j/10)){
					if (k != 0 && l != 0){
						ans.push_back(make_pair(i,j)); 
					}
				}
			}
		}
	}
	// now answer contains the four fractions. 
	int numer = 1, denom = 1;  
	for (int i = 0; i < ans.size(); i++){
		numer *= ans[i].first;  
		denom *= ans[i].second; 
	}
	denom /= gcd(numer,denom);
	cout << denom << endl;  
	return 0;  
}
