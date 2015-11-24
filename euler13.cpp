/*
Problem link: https://projecteuler.net/problem=13
This problem requires big int addition implementation. 
(we can probably use another mathematical method for this problem?? but whatever for now)
*/

#include <iostream>
#include <cstdlib> 
#include <string> 
#include <fstream> 
#include <algorithm> 
#include <vector> 
using namespace std; 

vector<string> v;  

string addition(string &s, string &t)
{
    int carry = 0, sum, i;
    string min = s, max = t, result = ""; 
    if (s.length() > t.length()){
        max = s; 
        min = t; 
    }
    else {
        max = t; 
        min = s; 
    }
    for (i = min.length()-1; i >= 0; --i)
    {
        sum = (min[i]-'0') + (max[i + max.length() - min.length()] - '0') + carry; 
        carry = sum/10; 
        sum %= 10; 
        result = (char)(sum + '0') + result; 
    }
    i = max.length() - min.length() - 1;  
    while (i >= 0)
    {
        sum = max[i] + carry - '0';  
        carry = sum/10; 
        sum %= 10; 
        result = (char)(sum + '0') + result;  
        --i; 
    }
    if (carry != 0) result = (char)(carry + '0') + result;  
    return result; 
}

int main(){
	ifstream fin("euler13.txt"); 
	string num; 
	while (fin >> num){
		v.push_back(num);  
	}
	string ans = "";  
	for (int i = 0; i < v.size(); i++){
		ans = addition(ans,v[i]); 
	}
	cout << ans.substr(0,10) << endl; 
	return 0; 
}
