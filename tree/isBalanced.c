#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "TreeShits.h"

bool isBalancedRetHeight(struct TreeNode *root,int *height) {
	if(NULL==root){
		*height=0;
		return true;
	}

	int l_d;
	if(!isBalancedRetHeight(root->left,&l_d)) return false;

	int r_d;
	if(!isBalancedRetHeight(root->right,&r_d)) return false;

	if(abs(l_d-r_d)>1) return false;

	*height= (l_d>r_d?l_d:r_d)+1;
	return true;
}

bool isBalanced(struct TreeNode* root) {
	int height=0;

	return isBalancedRetHeight(root,&height);
}

int main(){

	char t[]="{1,2,3,#,4,5,#,6,7,#,8,99}";
	struct TreeNode *r = make_tree(t);

	if(isBalanced(r)){
		puts("Balanced! ~~");
	}else{
		puts("No Balanced! ~~");
	}
	return 0;
}

