#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "TreeShits.h"

int maxDepth(struct TreeNode *root) {
	if(NULL==root) return 0;
    
	int l_d=maxDepth(root->left);
	int r_d=maxDepth(root->right);

	return l_d>r_d? l_d+1 : r_d+1;
}

int minDepth(struct TreeNode *root) {
	if(NULL==root) return 0;

	if(NULL==root->left && NULL==root->right)
		return 1;
    
	int l_d=minDepth(root->left);
	int r_d=minDepth(root->right);

	if(NULL!=root->left && NULL!=root->right){
		return l_d<r_d? l_d+1 : r_d+1;
	}
	// one sub branch is null
	return l_d>r_d? l_d+1 : r_d+1;
}

int main(){

	char t[]="{1,2,3,#,4,5,#,6,7,#,8,99}";
	struct TreeNode *r = make_tree(t);

	int re=minDepth(r);
	printf("ret :%d\n",re);
	return 0;
}

