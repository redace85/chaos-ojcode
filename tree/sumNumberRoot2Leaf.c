#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "TreeShits.h"

int sumNumbersRecursive(struct TreeNode* root,int preval) {
	if(NULL==root->left && NULL==root->right){
		return preval*10+root->val;
	}
	int ret=0;
	preval=preval*10+root->val;
	if(NULL!=root->left){
		ret+= sumNumbersRecursive(root->left,preval);
	}
	if(NULL!=root->right){
		ret+= sumNumbersRecursive(root->right,preval);
	}

	return ret;
}

int sumNumbers(struct TreeNode* root) {
	if(NULL==root) return 0;
    
	return sumNumbersRecursive(root,0);
}

int main(){

	//char t[]="{1,2,3,4,5,6,7,8}";
	char t[]="{1,2,3,4,5,6,7}";
	struct TreeNode *r = make_tree(t);

	int sum=sumNumbers(r);
	printf("count %d\n",sum);

	simple_inorder(r);
	puts("end of inorder");
	simple_preorder(r);
	puts("end of preorder");
	simple_suforder(r);
	puts("end of suforder");
}

