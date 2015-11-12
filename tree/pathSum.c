#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "TreeShits.h"

bool hasPathSum(struct TreeNode* root, int sum) {
	if(NULL==root) return false;

	if(NULL==root->left && NULL==root->right){
		return sum==root->val;
	}
	sum-=root->val;
    
	return hasPathSum(root->left,sum)||hasPathSum(root->right,sum);
}

int main(){

	char t[]="{5,4,8,11,#,13,4,7,2,#,#,#,1}";
	struct TreeNode *r = make_tree(t);

	if(hasPathSum(r,18)){
		puts("Ture");
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

