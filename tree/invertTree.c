#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "TreeShits.h"

bool in_order_validBST(struct TreeNode* node,struct TreeNode** prev) {
	if(NULL==node) return true;
    
	if(!in_order_validBST(node->left,prev)) return false;
	if(NULL!=(*prev) && (*prev)->val>= node->val) return false;

	*prev=node;

	return in_order_validBST(node->right,prev);
}

struct TreeNode* invertTree(struct TreeNode* root) {
	if(NULL==root) return root;
    
	struct TreeNode *i_l=invertTree(root->left);
	struct TreeNode *i_r=invertTree(root->right);
	root->left=i_r;
	root->right=i_l;

	return root;
}

int main(){

	char t[]="{4,2,7,1,3,6,9}";
	struct TreeNode *r = make_tree(t);

	simple_inorder(r);
	puts("end of inorder");

	invertTree(r);

	simple_inorder(r);
	puts("end of inorder");

}

