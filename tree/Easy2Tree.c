#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "TreeShits.h"

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
	struct TreeNode* cur=root;
	do{
		if(p->val <cur->val && q->val <cur->val){
			cur=cur->left;
		}else if(p->val >cur->val && q->val >cur->val){
			cur = cur -> right;
		}else return cur; 
	}while(true);
	return root;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {

	if (p->val<root->val && q->val<root->val)
		return lowestCommonAncestor(root->left,p,q);
	if (p->val>root->val && q->val>root->val)
		return lowestCommonAncestor(root->right,p,q);
	return root;
}

int main(){

	char t[]="{6,2,8,0,4,7,9,#,#,3,5}";
	struct TreeNode *r = make_tree(t);

	struct TreeNode *p = malloc(sizeof(struct TreeNode));
	p->val=3;
	struct TreeNode *q = malloc(sizeof(struct TreeNode));
	q->val=5;
	struct TreeNode *l=lowestCommonAncestor(r,p,q);

	printf("lc: %d\n", l->val);
	simple_inorder(r);
	puts("end ino");
	simple_preorder(r);
	puts("end pre");
}

