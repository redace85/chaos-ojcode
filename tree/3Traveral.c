#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "TreeShits.h"

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	int buff[255];
	*returnSize=0;
	struct TreeNode *cur=root;
	struct TreeNode *prev=NULL;
	while(cur){
		if(cur->left){
			prev=cur->left;
			while(prev->right && prev->right!=cur)
				prev=prev->right;

			if(prev->right){
				// just come from precessor
				prev->right=NULL;
				cur=cur->right;
			}else{
				prev->right=cur;
				buff[*returnSize]=cur->val;
				++(*returnSize);
				cur=cur->left;
			}

		}else{
			buff[*returnSize]=cur->val;
			++(*returnSize);
			cur=cur->right;
		}
	}
	int bs=sizeof(int)*(*returnSize);
	int *res=malloc(bs);

	memcpy(res,buff,bs);
	return res;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	int buff[255];
	*returnSize=0;
	struct TreeNode *cur=root;
	struct TreeNode *prev=NULL;
	while(cur){
		if(cur->left){
			prev=cur->left;
			while(prev->right && prev->right!=cur)
				prev=prev->right;

			if(prev->right){
				// just come from precessor
				prev->right=NULL;
				buff[*returnSize]=cur->val;
				++(*returnSize);
				cur=cur->right;
			}else{
				prev->right=cur;
				cur=cur->left;
			}

		}else{
			buff[*returnSize]=cur->val;
			++(*returnSize);
			cur=cur->right;
		}
	}
	int bs=sizeof(int)*(*returnSize);
	int *res=malloc(bs);

	memcpy(res,buff,bs);
	return res;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
	int buff[255];
	*returnSize=0;
	struct TreeNode dump;
	dump.left=root;
	dump.right=NULL;
	dump.val=0;
	struct TreeNode *cur=&dump;
	struct TreeNode *prev=NULL;
	while(cur){
		if(cur->left){
			prev=cur->left;
			while(prev->right && prev->right!=cur)
				prev=prev->right;

			if(prev->right){
				// just come from precessor
				struct TreeNode *p=cur->left;
				int rn=0;
				while(p!=cur){
					buff[*returnSize]=p->val;
					++(*returnSize);
					p=p->right;
					++rn;
				}
				//reverse right branch vals
				int pt=*returnSize -1;
				int ph=(*returnSize -rn);
				while(pt>ph){
					int tmp=buff[ph];
					buff[ph]=buff[pt];
					buff[pt]=tmp;
					--pt;
					++ph;
				}
				prev->right=NULL;
				cur=cur->right;
			}else{
				prev->right=cur;
				cur=cur->left;
			}

		}else{
			cur=cur->right;
		}
	}
	int bs=sizeof(int)*(*returnSize);
	int *res=malloc(bs);

	memcpy(res,buff,bs);
	return res;
}

int main(){

	char t[]="{1,2,3,#,4,5,#,6,7,#,8}";
	struct TreeNode *r = make_tree(t);

	int n;
	int *res =postorderTraversal(r,&n);
	int i=0;
	while(i<n){
		printf("%d,",res[i]);
		++i;
	}
	puts("show over");
	simple_inorder(r);
	puts("end of inorder");
	simple_preorder(r);
	puts("end of preorder");
	simple_suforder(r);
	puts("end of suforder");
}

