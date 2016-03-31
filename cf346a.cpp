#include <iostream>
using namespace std; 

int main(){
	int n,a,b; 
	cin >> n >> a >> b;  
	if (b > 0){
		for (int i = 0; i < b; i++){
			++a;  
			if (a > n) a = 1;  
		}
		cout << a << endl; 
	}else if (b < 0){
		b *= -1;  
		for (int i = 0; i < b; i++){
			--a;  
			if (a < 1) a = n;  
		}
		cout << a << endl; 
	}else{
		cout << a << endl; 
	}
	return 0; 
}
