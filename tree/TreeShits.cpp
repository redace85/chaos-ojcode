#include <iostream>
#include <string>
#include <queue>
using namespace std;

//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// inputs {2,#,4,842,3,#}
TreeNode * make_tree(const string& str){
	if(str.empty()&&str[0]!='{')
		return 0;
	// handle the root
	auto pos = str.find(',');
	if(pos ==string::npos){
		// only one num?
		auto len = str.length();
		if( len<=3 ){
			return 0;
		}
		auto sub = str.substr(1,len-2);

		return new TreeNode(atoi(sub.data()));
	}

	auto s_v = str.substr(1,pos-1);
	auto root = new TreeNode(atoi(s_v.data()));
	queue<TreeNode** > q;
	q.push(&(root->left));
	q.push(&(root->right));
	int c =2;
	while(c>0){
		int i = c;
		//cout<<"i:"<<i<<endl;
		c=0;
		while(i>0){
			auto p1 = pos+1;
			pos = str.find(',',p1);
			if(string::npos!=pos){
				//cout<<"pos:"<<pos<<endl;
				// positon found
				auto sub = str.substr(p1, pos-p1);
				if("#"!=sub) {
					auto point = q.front();

					*point = new TreeNode(atoi(sub.data()));
					q.push(&((*point)->left));
					q.push(&((*point)->right));
					c+=2;
				}
				q.pop();
			} else {
				// end of string
				c=0;
				break;
			}
			--i;
		}
	}
	return root;
}

void simple_inorder(TreeNode *t){
	cout<< t->val <<' ';
	
	if(t->left!=NULL){
		simple_inorder(t->left);
	}

	if(t->right!=NULL){
		simple_inorder(t->right);
	}
}

void simple_preorder(TreeNode *t){
	if(t->left!=NULL){
		simple_preorder(t->left);
	}

	cout<< t->val <<' ';

	if(t->right!=NULL){
		simple_preorder(t->right);
	}
}

void simple_suforder(TreeNode *t){
	if(t->left!=NULL){
		simple_suforder(t->left);
	}

	if(t->right!=NULL){
		simple_suforder(t->right);
	}

	cout<< t->val <<' ';
}

int main(){

	string t("{1,2,3,#,4,5,#,6,7,#,8,}");
	auto r = make_tree(t);

	simple_inorder(r);
	cout << endl;
	simple_preorder(r);
	cout << endl;
	simple_suforder(r);
	cout << endl;
}

