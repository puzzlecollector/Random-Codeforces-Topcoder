// Problem Link: http://codeforces.com/contest/612/problem/C 
// We use the stack to store opening brackets and every time we meet closing brackets, there are three 
// cases: 1)stack is empty: no solution, 2) stack.top() has same type as closing bracket, 3) stack.top() has different type 
// as closing bracket (i.e. increment cnt by 1). Of course, there is one more edge case, which is that 
// when we finish going over the entire string, the stack should be empty for the brackets to have been completely matched. 
// If the stack is not empty, it means that there is an unmatched opening bracket, so in this case we should print "Impossible"
// instead. 

#include <iostream> 
#include <cstdlib> 
#include <string>
#include <cstring>  
#include <stack> 
#include <algorithm> 
using namespace std; 

bool sameType(char open, char close){
	if (open == '<' && close == '>') return true; 
	if (open == '{' && close == '}') return true; 
	if (open == '[' && close == ']') return true; 
	if (open == '(' && close == ')') return true; 
	return false;  
}

int main(){
	string s;  
	cin >> s; 
	stack<char> st; 
	int cnt = 0;  
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '<' || s[i] == '{' || s[i] == '[' || s[i] == '('){
			st.push(s[i]); 
		}else if (s[i] == '>' || s[i] == '}' || s[i] == ']' || s[i] == ')'){
			if (st.empty()){
				cout << "Impossible" << endl; 
				return 0; 
			}else if (sameType(st.top(),s[i])){
				st.pop(); 
			}else{
				st.pop();  
				++cnt; 
			}
		} 
	}
	if (st.empty()){
		cout << cnt << endl; 
	}else{
		cout << "Impossible" << endl; 
	}
	return 0; 
}
