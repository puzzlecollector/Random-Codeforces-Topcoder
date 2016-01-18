#include <iostream> 
#include <cstdlib> 
#include <string> 
using namespace std; 

typedef long long ll;

string a,b;  
int cnt[2]; 

int main(){
	cin >> a >> b;  
	int lena = (int)a.size(), lenb = (int)b.size();  
	ll ans = 0; 
	for (int i = 0; i < lenb; i++){
		cnt[b[i]]++;  
		if (i >= lenb-lena){
			ans += lenb-lena+1-cnt[a[i-lenb+lena]];  
			cnt[b[i-lenb+lena]]--;  
		}
	}
	cout << ans << endl; 
	return 0; 
}
