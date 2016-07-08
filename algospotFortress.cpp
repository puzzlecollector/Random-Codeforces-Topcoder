#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <algorithm> 
#include <vector> 
#include <string> 
using namespace std;  

struct TreeNode{
	vector<TreeNode *> children; // 자손 노드들을 가리키는 포인터들의 배열 
}; 

int n,y[100],x[100],radius[100]; 
int sqr(int x){
	return x*x; 
}
int sqrdist(int a,int b){
	return sqr(y[a]-y[b])+sqr(x[a]-x[b]);  
}
bool enclose(int a,int b){
	return radius[a]>radius[b] && sqrdist(a,b) < sqr(radius[a]-radius[b]);  
}
bool isChild(int parent,int child){
	if (!enclose(parent,child)) return false; 
	for (int i = 0; i < n; i++){
		if (i != parent && i != child && enclose(parent,i) && enclose(i,child)) return false; 
	}
	return true;  
}


int longest;  

int height(TreeNode *root){
	// 각 자식들을 루트로 하는 서브트리의 높이를 구한다.  
	vector<int> heights; 
	for (int i = 0; i < root->children.size(); i++){
		heights.push_back(height(root->children[i]));  
	}
	// 만약 자식이 하나도 없다면 0을 반환한다. 
	if (heights.empty()) return 0; 
	sort(heights.begin(),heights.end());  
	// root를 최상위 노드로 하는 경로를 고려한다. 
	if (heights.size() >= 2){
		longest = max(longest,2+heights[heights.size()-2]+heights[heights.size()-1]);  
	}
	return heights.back()+1;  
}

int solve(TreeNode *root){
	longest = 0;  
	int h = height(root);  
	return max(longest,h);  
}

TreeNode *getTree(int root){
	TreeNode *ret = new TreeNode();  
	for (int ch = 0; ch < n; ch++){
		if (isChild(root,ch)){
			ret->children.push_back(getTree(ch));  
		}
	}
	return ret;  
}


int main(){
	int t; 
	scanf("%d",&t);  
	while (t--){
		scanf("%d",&n);  
		for (int i = 0; i < n; i++){
			scanf("%d %d %d",&x[i],&y[i],&radius[i]);  
		}
		TreeNode *root = getTree(0); 
		printf("%d\n",solve(root));  
	}
	return 0; 
}
