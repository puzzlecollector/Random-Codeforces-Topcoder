// Code by Luke Minsuk Kim 
// email: mkim14@stanford.edu 
#include <iostream>
#include <algorithm>
#include <set>
#include <vector> 
using namespace std; 
int main(int argc,char *argv[]){
	set< vector<int> > res; 
	for (int i = 0; i < (1<<5); i++){
		vector<int> binary; 
		int temp = i; 
		while (temp){
			binary.push_back(temp%2); 
			temp /= 2;  
		}
		while (binary.size() < 5){
			binary.push_back(0); 
		}
		reverse(binary.begin(),binary.end()); 
		if ((binary[0] == 1 && binary[1] == 1) || 
			(binary[2] == 1 && binary[3] == 1) || 
			(binary[0] == 1 && binary[2] == 1 && binary[4] == 1)){
			res.insert(binary);  
		} 
	}
	cout << res.size() << endl; 
	cout << "Listing all sequences in the sample space W" << endl; 
	for (set< vector<int> >::iterator it = res.begin(); it != res.end(); it++){
		vector<int> v = *it; 
		for (int j = 0; j < v.size(); j++){
			cout << v[j]; 
		}
		cout << endl; 
	}
	return 0; 
}
