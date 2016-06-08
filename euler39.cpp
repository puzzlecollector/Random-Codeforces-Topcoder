#include <iostream> 
#include <cstdio> 
#include <cmath> 
#include <map> 
#include <algorithm> 
using namespace std; 

bool isPerfectSquare(int x){
	return (sqrt(x) == floor(sqrt(x))); 
}

int main(){
	map<int,int> mp; 
	for (int a = 1; a <= 1000; a++){
		for (int b = 1; b <= 1000; b++){
			int cSquared = a*a+b*b; 
			if (isPerfectSquare(cSquared)){
				if (a+b+sqrt(cSquared) < 1000) mp[a+b+sqrt(cSquared)]++; 
			}
		}
	}
	int maxP = 0, ans;  
	for (map<int,int>::iterator it = mp.begin(); it != mp.end(); it++){
		if (it->second > maxP){
			maxP = it->second;  
			ans = it->first;  
		}
	}
	printf("%d\n",ans);  
	return 0;  
}
