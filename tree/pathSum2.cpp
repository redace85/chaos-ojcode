#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
#include <vector>

#include "TreeShits.h"

using namespace std;

vector<vector<int>> pathSum(TreeNode* root, int sum) {
	vector<vector<int>> res;
	if(!root)
		return res;

	if(!root->left && !root->right){
		if(sum == root->val)
			res.push_back(vector<int>(1,sum));
		return res;
	}

	sum-=root->val;
	auto left_res=pathSum(root->left,sum);
	for(auto r: left_res){
		r.insert(r.begin(),root->val);
		res.push_back(r);
	}

	auto right_res=pathSum(root->right,sum);
	for(auto r: right_res){
		r.insert(r.begin(),root->val);
		res.push_back(r);
	}
	return res;
}

int main(){

	string t("{5,4,8,11,#,13,4,7,2,#,#,5,1}");
	auto r = make_tree(t.c_str());

	auto some = pathSum(r,22);
	cout<<"show Fun"<<endl;
	for(auto x:some){
		for(auto i:x){
			cout<<i<<",";
		}
		cout<<endl;
	}
	//simple_suforder(r);
	cout << endl;
}

