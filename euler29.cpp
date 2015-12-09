/*
Problem Link: https://projecteuler.net/problem=29
Because I like brute forcing, let us brute force this problem too... we are generating all 
999*999 = 998001 combinations and checking if there are any duplicates. 
*/
#include <iostream> 
#include <vector> 
#include <cstdlib> 
#include <algorithm> 
#include <cstring> 
#include <string> 
#include <sstream> 
#include <map> 
#include <ctime> 
using namespace std;

// big number multiplication implementation.
using namespace std; 
#define OVERFLOW 2 
#define ROW b_len 
#define COL a_len+b_len+OVERFLOW 
 
int getCarry(int num)
{
    int carry = 0;  
    if (num >= 10){
        while (num != 0){
            carry = num%10; 
            num /= 10;  
        }
    }
    else carry = 0;  
    return carry; 
}
 
int num(char a){
    return int(a) - 48; 
}
 
string mult(string a, string b)
{
    string ret; 
    int a_len = a.length(); 
    int b_len = b.length(); 
    int mat[ROW][COL]; 
    for (int i = 0; i < ROW; ++i){
        for (int j = 0; j < COL; ++j){
            mat[i][j] = 0;  
        }
    }
    int carry = 0, n,x = a_len - 1, y = b_len - 1;  
    for (int i = 0; i < ROW; ++i){
        x = a_len - 1; 
        carry = 0;  
        for (int j = (COL-1)-i; j >= 0; --j)
        {
            if ((x >= 0) && (y >= 0)){
                n = (num(a[x])*num(b[y])) + carry; 
                mat[i][j] = n%10;  
                carry = getCarry(n); 
             }
             else if ((x >= -1) && (y >= -1)) mat[i][j] = carry; 
             x = x-1;  
        }
        y = y-1; 
    }
    carry = 0;  
    int sum_arr[COL]; 
    for (int i = 0; i < COL; ++i) sum_arr[i] = 0; 
    for (int i = 0; i < ROW; ++i) {
        for (int j = COL-1; j >= 0; --j){
            sum_arr[j] += (mat[i][j]); 
        }
    }
    int temp;  
    for (int i = COL-1; i >= 0; --i)
    {
        sum_arr[i] += carry;  
        temp = sum_arr[i]; 
        sum_arr[i] = sum_arr[i]%10;   
        carry = getCarry(temp); 
    }
    for (int i = 0; i < COL; ++i)
    {
        ret.push_back(char(sum_arr[i] + 48)); 
    }
    while (ret[0] == '0'){
        ret = ret.substr(1,ret.length()-1); 
    }
    return ret; 
}
 
void printhuge(string a){
    for (string::iterator it = a.begin(); it != a.end(); ++it){
        cout << *it;  
    }
    cout << endl;
}

string intToString(int n){
	stringstream ss; 
	ss << n; 
	return ss.str(); 
}

clock_t clock(); 

int main(){
	clock_t tic,toc; 
	double duration;  
	tic = clock();  
	vector<string> storeDistinct; 
	for (int base = 2; base <= 100; base++){
		for (int power = 2; power <= 100; power++){
			string a = intToString(base); 
			string b = a; 
			for (int i = 2; i <= power; i++){
				b = mult(b,a); 
				if (find(storeDistinct.begin(),storeDistinct.end(),b) == storeDistinct.end()){
					storeDistinct.push_back(b); 
				}
			}
		}
	}
	cout << storeDistinct.size() << endl; 
	toc = clock();  
	duration = (double)(tic-toc)/CLOCKS_PER_SEC;  
	cout << "took " << duration << "seconds" << endl; 
	return 0; 
}
