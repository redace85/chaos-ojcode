#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "TreeLinkShits.h"

//Definition for binary tree with next pointer.
/*struct TreeLinkNode {
	 int val;
	 struct TreeLinkNode *left, *right, *next;
	};
*/

void dfs_fun(struct TreeLinkNode* node,struct TreeLinkNode* next) {
	if(NULL==node) return;
	node->next=next;

	// find the one beyond right branch
	struct TreeLinkNode *beyond_r=NULL;
	while(NULL!=next){
		if(NULL!=next->left){
			beyond_r=next->left;
			break;
		}

		if(NULL!=next->right){
			beyond_r=next->right;
			break;
		}

		next=next->next;
	}

	dfs_fun(node->right,beyond_r);
	dfs_fun(node->left,node->right?node->right:beyond_r);
}

void connect(struct TreeLinkNode *root) {
	dfs_fun(root,NULL);
}

void connectIte(struct TreeLinkNode *root) {
    if (NULL==root) return;

    struct TreeLinkNode *cur=root;
    struct TreeLinkNode *pre=root;
    struct TreeLinkNode *end=root;

    do{
		if(cur->left){
			pre->next=cur->left;
			pre=pre->next;
		}

		if(cur->right){
			pre->next=cur->right;
			pre=pre->next;
		}

		if(cur!=end){
			cur=cur->next;
		}else{
			cur=cur->next;
			end->next=NULL;
			end=pre;
		}
    } while(cur);
}

void printByRow(struct TreeLinkNode *r){
	while(r){
		struct TreeLinkNode *p=r;
		do{
			printf("%d ",p->val);
			p=p->next;
		} while(p);
		puts("#");
		r=r->left;
	}
}

int main(){

	//char t[]="{1,2,3,4,5,#,6,7,#,#,#,#,8}";
	char t[]="{1,2,3,4,5,#,6,7,#,#,#,#,8}";
	struct TreeLinkNode *r = make_tree(t);

	connectIte(r);

	printByRow(r);

	simple_inorder(r);
	puts("end of inorder");
	simple_preorder(r);
	puts("end of preorder");
	simple_suforder(r);
	puts("end of suforder");
}

