#include <iostream> 
using namespace std; 

int factorial(int n){
	int prod = 1;  
	for (int i = 2; i <= n; i++){
		prod *= i; 
	}
	return prod;  
}

int main(){
	int sum = 0; 
	for (int i = 11;i <= 2540160;i++){
		int num = i;  
		int temp = 0;  
		while (num){
			temp += factorial(num%10); 
			num /= 10;  
		}	
		if (i == temp) sum += i;  
	}
	printf("%d\n",sum); 
	return 0;  
}
