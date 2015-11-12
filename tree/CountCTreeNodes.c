#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "TreeShits.h"

int recursiveCountWithHeight(struct TreeNode* root,int height) {
	if(NULL==root) return 0;

	struct TreeNode *p=root;
	int r_h=0;
	while(NULL!=p){
		++r_h;
		p=p->right;
	}

	if(height==r_h){
		return pow(2,height)-1;
	}else{
		return 1+recursiveCountWithHeight(root->left,height-1)
			+recursiveCountWithHeight(root->right,height-1);
	}
}

int countNodes(struct TreeNode* root) {
	if(NULL==root) return 0;

	struct TreeNode *p=root;
	int height=0;
	// left height only needs to be calculated once
	while(NULL!=p){
		++height;
		p=p->left;
	}

	return recursiveCountWithHeight(root,height);
}

int main(){

	//char t[]="{1,2,3,4,5,6,7,8}";
	char t[]="{1,2,3,4,5,6,7}";
	struct TreeNode *r = make_tree(t);

	int cc=countNodes(r);
	printf("count %d\n",cc);

	simple_inorder(r);
	puts("end of inorder");
	simple_preorder(r);
	puts("end of preorder");
	simple_suforder(r);
	puts("end of suforder");
}

