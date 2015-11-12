#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
#include <vector>
#include <queue>

#include "TreeShits.h"

using namespace std;

vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>> res;
	if(!root)
		return res;
	queue<TreeNode*> q;
	q.push(root);
	vector<int> v;
	while(!q.empty()){
		int n=q.size();
		while(n>0){
			auto node=q.front();
			v.push_back(node->val);
			if(node->left)
				q.push(node->left);
			if(node->right)
				q.push(node->right);
			q.pop();
			--n;
		}
		res.emplace_back(v);
		v.clear();
	}
	reverse(res.begin(),res.end());
	return res;
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	vector<vector<int>> res;
	if(!root)
		return res;
	queue<TreeNode*> q;
	q.push(root);
	vector<int> v;
	bool b_rev=false;
	while(!q.empty()){
		int n=q.size();
		while(n>0){
			auto node=q.front();
			v.push_back(node->val);
			if(node->left)
				q.push(node->left);
			if(node->right)
				q.push(node->right);
			q.pop();
			--n;
		}
		if(b_rev)
			reverse(v.begin(),v.end());
		res.emplace_back(v);
		v.clear();
		b_rev=!b_rev;
	}
	return res;	
}

int main(){
	string t("{3,9,20,#,#,15,7}");
	auto r = make_tree(t.c_str());

	auto some=zigzagLevelOrder(r);
	
	cout<<"show Fun"<<endl;;
	for(auto x:some){
		for(auto i:x){
			cout<<i<<",";
		}
		cout<<endl;
	}
	//simple_suforder(r);
	//cout << endl;
}

