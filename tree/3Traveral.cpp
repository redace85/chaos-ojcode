#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
#include <vector>

#include "TreeShits.h"

using namespace std;

vector<int> preorderTraversal(TreeNode* root) {
	vector<int> res;
	if(NULL==root)
		return res;

	stack<TreeNode *> st;
	st.push(root);
	while(!st.empty()){
		auto node=st.top();
		st.pop();
		if(node->right) st.push(node->right);
		if(node->left) st.push(node->left);
		res.push_back(node->val);
	}
	return res;
}

vector<int> inorderTraversal(TreeNode* root) {
	vector<int> res;
	TreeNode *cur=root;
	TreeNode *prev=NULL;
	while(cur){
		if(cur->left){
			prev=cur->left;
			while(prev->right && prev->right!=cur)
				prev=prev->right;

			if(prev->right){
				// just come from precessor
				prev->right=NULL;
				res.push_back(cur->val);
				cur=cur->right;
			}else{
				prev->right=cur;
				cur=cur->left;
			}

		}else{
			res.push_back(cur->val);
			cur=cur->right;
		}
	}

	return res;
}

int main(){

	string t("{1,2,3,#,4,5,#,6,7,#,8}");
	auto r = make_tree(t.c_str());

	simple_inorder(r);
	cout << endl;
	simple_preorder(r);
	cout << endl;

	auto some=preorderTraversal(r);
	
	cout<<"show Fun";
	for(auto x:some){
		cout<<x;
	}
	cout<<endl;
	//simple_suforder(r);
	//cout << endl;
}

