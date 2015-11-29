/*
Problem Link: https://projecteuler.net/problem=19
We are provided with the following information: 
- 1 Jan 1900 was a monday 
- months 4,6,9,11 has 30 days 
- months 1,3,5,7,8,10,12 has 31 days 
- months 2 has 28 days and 29 days on leap years. 
- a leap year is divisible by 4 and not by 100 or divisible by 400. 
We are asked to find how many Sundays fell on the first of the month during the 20th century. 
(1901, Jan 1 to 2000 Dec 31) 
*/

#include <iostream> 
#include <cstdlib> 
using namespace std; 

int main(){
	int cnt = 0, days, passed = 0; 
	for (int i = 1901; i <= 2000; i++){
		for (int j = 1; j <= 12; j++){
			if (j == 4 || j == 6 || j == 9 || j == 11){
				days = 30; 
			}else if (j == 2){
				if (i%400 == 0 || (i%4 == 0 && i%100 != 0)){
					days = 29; 
				}else days = 28;  
			}else{
				days = 31; 
			}
			if (passed%7 == 0) ++cnt;  
			passed += days; 
		}
	}
	cout << cnt << endl;
	return 0; 
}
