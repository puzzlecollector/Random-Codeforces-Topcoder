// Problem link: https://projecteuler.net/problem=6
#include <iostream>
using namespace std; 

int main(){
	int sum_of_sq = (100)*(100+1)*(2*100+1)/6;  
	int sq_of_sum = ((100)*(100+1)/2)*(100*(100+1)/2); 
	cout << sq_of_sum - sum_of_sq << endl;
	return 0; 
}
