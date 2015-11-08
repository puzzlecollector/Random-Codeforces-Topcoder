/*Given two positive integers a,b, it prints the 
result of a/b and also tells us if it is a repeating decimal or not. 
*/

#include <iostream>
using namespace std; 

void printDecimal(int a, int b){
	int iter = 0; 
	while (a > 0){
		if (iter == b+1){
			cout << "..." << endl; 
			cout << "This is a repeating decimal"; 
			break; 
		}
		if (iter++ == 1){
			cout << "."; 
		}
		cout << a/b; 
		a = (a%b)*10; 
	}
}

int main(){
	int a,b; 
	cin >> a >> b; 
	printDecimal(a,b); 
	cout << endl;
	return 0; 
}
