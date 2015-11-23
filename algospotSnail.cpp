/*
Problem link: https://algospot.com/judge/problem/read/SNAIL
비가 오면 2미터 올라가고, 날이 맑으면 1미터 올라간다. m일간 비가 올 확률이 정확이 75%이다. 
*/
#include <iostream> 
#include <cstdlib> 
#include <algorithm> 
#include <cstdio> 
#include <cstring> 
#include <cmath> 
using namespace std; 

int c,n,m; 

double cache[1000][2001]; 

double probability(int days, int climbed){
	if (days == m) return climbed >= n ? 1.0:0.0;  
	double& ret = cache[days][climbed];  
	if (ret != -1) return ret; 
	ret = 0.75*probability(days+1,climbed+2) + 0.25*probability(days+1,climbed+1);  
	return ret;  
}

int main(){
	scanf("%d",&c);  
	for (int i = 0; i < c; i++){
		for (int j = 0; j < 1000; j++){
			for (int k = 0; k < 2001; k++){
				cache[j][k] = -1;  
			}
		}
		scanf("%d%d",&n,&m);  
		double ans = probability(0,0); 
		printf("%.10lf\n",ans);  
	}
	return 0; 
}
