/*
Problem Link: https://projecteuler.net/problem=25
Because we have to find the nth fibonacci number that contains 1000 digits, 
one possible way to do this is to simulate big number addition. 
*/

// big number addition using std::string. 
#include <iostream> 
#include <string> 
#include <cstdlib>
using namespace std; 
 
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
 
int main()
{
    string a = "1", b = "1", c = ""; 
    int idx = 2; 
    while (c.size() < 1000){
    	++idx;  
    	c = addition(a,b); 
    	a = b; 
    	b = c; 
    }
    cout << idx << endl; 
    return 0; 
}
