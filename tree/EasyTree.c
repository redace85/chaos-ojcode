#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "TreeShits.h"

bool isSameTree(struct TreeNode *p, struct TreeNode *q) {
	if(NULL==p && NULL==q) return true;
    
	if(NULL!=p && NULL!=q){
		if(p->val==q->val &&
				isSameTree(p->left,q->left) &&
				isSameTree(p->right,q->right) ){
			return true;
		} else {
			return false;
		}

	}
	return false;
}

bool isMirror(struct TreeNode *p, struct TreeNode *q) {
	if(NULL==p && NULL==q) return true;
    
	if(NULL!=p && NULL!=q){
		if(p->val==q->val &&
				isMirror(p->left,q->right) &&
				isMirror(p->right,q->left) ){
			return true;
		} else {
			return false;
		}

	}
	return false;
	
}

bool isSymmetric(struct TreeNode *root) {
	if(NULL==root||
			(NULL==root->right && NULL==root->left))
		return true;
    
	if(NULL!=root->right && NULL!=root->left){
		return isMirror(root->right,root->left);
	}
	return false;
}

int main(){

	char t[]="{1,2,3,#,4,5,#,6,7,#,8}";
	char t2[]="{1,2,3,#,4,5,#,6,7,8,2}";
	struct TreeNode *r = make_tree(t);
	struct TreeNode *r2 = make_tree(t2);

	if(isSameTree(r,r2)){
		puts("same Tree");
	} else {
		puts("diff Tree");
	}
	printf("after t%s\n",t);

	char st[]="{1,2,2,3,4,4,3}";
	struct TreeNode *sr = make_tree(st);

	simple_inorder(sr);
	puts("end ino");
	simple_preorder(sr);
	puts("end pre");
	if(isSymmetric(sr)){
		puts("symmetric Tree");
	} else {
		puts("no sym Tree");
	}
}

