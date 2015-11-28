/*
Problem Link: https://projecteuler.net/problem=17
Finding the number of letters when all the numbers from 1 to 1000 are written out in words. 
This is a non mathematical brute force way of solving the problem (using recursion). 
*/

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring> 
#include <string> 
#include <sstream>
using namespace std; 

string intToString(int n){
	stringstream ss; 
	ss << n; 
	return ss.str(); 
}

string recur(string num){
	if (num.size() == 1){
		if (num == "0") return ""; 
		else if(num == "1") return "one";  
		else if (num == "2") return "two"; 
		else if (num == "3") return "three"; 
		else if (num == "4") return "four"; 
		else if (num == "5") return "five"; 
		else if (num == "6") return "six"; 
		else if (num == "7") return "seven"; 
		else if (num == "8") return "eight"; 
		else if (num == "9") return "nine"; 
 	}
 	if (num.size() == 2){
 		if (num[0] == '0') return recur(num.substr(1)); 
 		else if (num[0] == '1'){
 			if (num == "10") return "ten"; 
 			else if (num == "11") return "eleven";
 			else if (num == "12") return "twelve"; 
 			else if (num == "13") return "thirteen"; 
 			else if (num == "14") return "fourteen"; 
 			else if (num == "15") return "fifteen"; 
 			else if (num == "16") return "sixteen"; 
 			else if (num == "17") return "seventeen"; 
 			else if (num == "18") return "eighteen";
 			else if (num == "19") return "nineteen"; 
 		}else if (num[0] == '2') return "twenty"+recur(num.substr(1)); 
 		else if (num[0] == '3') return "thirty"+recur(num.substr(1)); 
 		else if (num[0] == '4') return "forty"+recur(num.substr(1)); 
 		else if (num[0] == '5') return "fifty"+recur(num.substr(1)); 
 		else if (num[0] == '6') return "sixty"+recur(num.substr(1)); 
 		else if (num[0] == '7') return "seventy"+recur(num.substr(1));  
 		else if (num[0] == '8') return "eighty"+recur(num.substr(1)); 
 		else if (num[0] == '9') return "ninety"+recur(num.substr(1)); 
 		
 	}
 	if (num.size() == 3){
 		if (num[0] == '1'){
 			if (num[1] == '0' && num[2] == '0') return "onehundred"; 
 			else return "onehundredand"+recur(num.substr(1));
 		}
 		else if (num[0] == '2'){
 			if (num[1] == '0' && num[2] == '0') return "twohundred";  
 			else return "twohundredand"+recur(num.substr(1)); 
 		}
 		else if (num[0] == '3'){
 			if (num[1] == '0' && num[2] == '0') return "threehundred"; 
 			else return "threehundredand"+recur(num.substr(1)); 
 		} 
 		else if (num[0] == '4'){
 			if (num[1] == '0' && num[2] == '0') return "fourhundred"; 
 			else return "fourhundredand"+recur(num.substr(1));
 		} 
 		else if (num[0] == '5'){
 			if (num[1] == '0' && num[2] == '0') return "fivehundred"; 
 			else return "fivehundredand"+recur(num.substr(1)); 
 		}  
 		else if (num[0] == '6'){
 			if (num[1] == '0' && num[2] == '0') return "sixhundred";  
 			else return "sixhundredand"+recur(num.substr(1));
 		}  
 		else if (num[0] == '7'){
 			if (num[1] == '0' && num[2] == '0') return "sevenhundred"; 
 			else return "sevenhundredand"+recur(num.substr(1));
 		}  
 		else if (num[0] == '8'){
 			if (num[1] == '0' && num[2] == '0') return "eighthundred";  
 			else return "eighthundredand"+recur(num.substr(1));
 		}  
 		else if (num[0] == '9'){
 			if (num[1] == '0' && num[2] == '0') return "ninehundred"; 
 			else return "ninehundredand"+recur(num.substr(1));
 		}  
 	}
 	// if num.size() == 4, then it must be one thousand. 
 	return "onethousand";
}

int main(){
	string t = ""; 
	for (int i = 1; i <= 1000; i++){
		string s = intToString(i);  
		t += recur(s);  
	}
	cout << t.size() << endl; 
	return 0; 
}
