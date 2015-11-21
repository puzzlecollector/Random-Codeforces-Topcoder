/*
Problem Link: https://projecteuler.net/problem=9
We can brute force to find an answer by looping for less than 10^6 times. 
Note: I tried to use a goto statement for breaking out of the double for loop, 
but goto statements are normally considered harmful (so we should try not to use it for most programs).  
Well, maybe not harmful, but it may lead to a confusingly structured code for large projects. 
For more information, refer to this link: http://stackoverflow.com/questions/3517726/what-is-wrong-with-using-goto
*/

#include <iostream>
#include <cmath> 
#include <algorithm> 
using namespace std; 

bool isPythagTriple(int a, int b, int c){
	int smallest = min(a,min(b,c)); 
	int largest = max(a,max(b,c));  
	int between; 
	if (a != largest && a!= smallest) between = a;  
	if (b != largest && b != smallest) between = b; 
	if (c != largest && c != smallest) between = c;   
	return smallest*smallest + between*between == largest*largest;  
}

int main(){
	for (int a = 1; a <= 1000; a++){
		for (int b = 1; b <= 1000; b++){
			int c = 1000-a-b;  
			if (a > 0 && b > 0 && c > 0 && isPythagTriple(a,b,c)){
				int ans = a*b*c; 
				cout << ans << endl; 
				goto stop; 
			}
		}
	}
	stop: 
	return 0; 
}
