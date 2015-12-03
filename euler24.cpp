/*
Problem Link: https://projecteuler.net/problem=24
Because there are only 10! cases to look for, we don't have to use a clever way of 
finding the millionth permutation. Simply make all permutations and when we reach the millionth one, 
print it to console. 
Note that in C++, std::next_permutation() makes the problem solving process much easier, but it is also simple 
to just implement a function that generates permutations as well. 
*/

#include <iostream> 
#include <cstdlib> 
#include <algorithm> 
using namespace std;  

int main(){
	int a[10] = {0,1,2,3,4,5,6,7,8,9}; 
	int cnt = 0; 
	do{
		if (++cnt == 1000000){
			for (int i = 0; i < 10; i++) cout << a[i]; 
			cout << endl; 
			break; 
		} 
	}while(next_permutation(a,a+10)); 
	return 0; 
}
