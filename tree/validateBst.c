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

bool isValidBST(struct TreeNode* root) {

	struct TreeNode *ptmp=NULL;
	return in_order_validBST(root,&ptmp);
}

int main(){

	//char t[]="{1,2,3,#,4,5,#,6,7,#,8}";
	char t[]="{1,1}";
	struct TreeNode *r = make_tree(t);

	if(isValidBST(r)){
		puts("True");
	}else{
		puts("False");
	}

	simple_inorder(r);
	puts("end of inorder");
	simple_preorder(r);
	puts("end of preorder");
	simple_suforder(r);
	puts("end of suforder");
}

