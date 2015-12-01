/*
Problem Link: https://projecteuler.net/problem=22
This is an implementation problem. We use file I/O and sorting "cleverly".   
Note that the names are all given in a single line and this may make the file I/O implementations 
slightly trickier. But still ez!! \^o^/ 
*/
#include <iostream>
#include <fstream>  
#include <string> 
#include <sstream> 
#include <vector> 
#include <algorithm> 
using namespace std;

int getNameScore(string s){
	int sum = 0; 
	for (int i = 0; i < s.size(); i++){
		sum += (s[i]-64); 
	}
	return sum; 
}

int main(){
	vector<string> names; 
	ifstream fin("euler22.txt"); 
	// record line of the file into a string, then 
	// use stringstream to split on commas. 
	while (fin){
		string input;  
		if (!getline(fin,input)) break; 
		stringstream ss; 
		ss << input; 
		while (ss){
			string s; 
			if (!getline(ss,s,',')) break; 
			names.push_back(s); 
		}
	}
	// get rid of double quotations 
	for (int i = 0; i < names.size();i++){
		names[i].erase(0,1); 
		names[i].erase(names[i].size()-1,1);
	}	
	// sort names in alphabetical order. 
	sort(names.begin(),names.end()); 
	long long score = 0; 
	for (int i = 0; i < names.size(); i++){
		score += (i+1)*getNameScore(names[i]); 
	}
	cout << score << endl; 
	return 0; 
} 
