// educational 9A 
#include <iostream>
#include <stack>
#include <cstdlib>
#include <string>
using namespace std; 

int main(){
	stack<string> st; 
	int n,p; 
	cin >> n >> p; 
	string s; 
	for (int i = 0; i < n; i++){
		cin >> s;  
		st.push(s);  
	}
	long long num = 0; 
	while (!st.empty()){
		string prompt = st.top(); st.pop(); 
		if (prompt == "halfplus"){
			num = 2*num+1;    
		}else{
			num *= 2;  
		}
	}
	long long val = 0; 
	while (num){
		if (num%2 == 1){
			val += (num/2)*p + p/2;  
		}else{
			val += (num/2)*p; 
		}
		num /= 2;  
	}
	cout << val << endl;
	return 0; 
}
