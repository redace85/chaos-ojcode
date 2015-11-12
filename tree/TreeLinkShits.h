//Definition for singly-linked list.
// and I implies a queue.
struct ListNode {
    struct TreeLinkNode **pnode;
    struct ListNode *next;
};

//Definition for binary tree
struct TreeLinkNode {
    int val;
	struct TreeLinkNode *left, *right, *next;
};

// inputs {2,#,4,842,3,#}
struct TreeLinkNode * make_tree(char str[]){
	if(0==strlen(str)&&str[0]!='{')
		return 0;
	char delimiter[]=" {},";
	// handle the root
	char *pos=strtok(str,delimiter);
	if(NULL==pos){
		// no token
		return 0;
	}

	struct TreeLinkNode *root=malloc(sizeof(struct TreeLinkNode));
	root->val=atoi(pos);
	root->left=NULL;
	root->right=NULL;

	struct ListNode *phead=malloc(sizeof(struct ListNode));
	struct ListNode *ptail=malloc(sizeof(struct ListNode));
	phead->pnode= &(root->left);
	phead->next=ptail;
	ptail->pnode= &(root->right);
	ptail->next=NULL;
	int c =2;
	while(c>0){
		int i = c;
		//cout<<"i:"<<i<<endl;
		c=0;
		while(i>0){
			pos = strtok(NULL,delimiter);
			if(NULL!=pos){
				struct ListNode *p=phead;

				if(0!=strcmp("#",pos)) {
					struct TreeLinkNode *point=malloc(sizeof(struct TreeLinkNode));
					point->val=atoi(pos);
					point->left=NULL;
					point->right=NULL;
					(*p->pnode)=point;
					ptail->next=malloc(sizeof(struct ListNode));
					ptail=ptail->next;
					ptail->pnode=&(point->left);

					ptail->next=malloc(sizeof(struct ListNode));
					ptail=ptail->next;
					ptail->pnode=&(point->right);
					ptail->next=NULL;
					c+=2;
				}
				phead=phead->next;
				free(p);
			} else {
				// end of string
				c=0;
				break;
			}
			--i;
		}
	}
	return root;
}

void simple_inorder(struct TreeLinkNode *t){
	if(t->left!=NULL){
		simple_inorder(t->left);
	}

	printf("%d ",t->val);

	if(t->right!=NULL){
		simple_inorder(t->right);
	}
}

void simple_preorder(struct TreeLinkNode *t){
	printf("%d ",t->val);

	if(t->left!=NULL){
		simple_preorder(t->left);
	}

	if(t->right!=NULL){
		simple_preorder(t->right);
	}
}

void simple_suforder(struct TreeLinkNode *t){
	if(t->left!=NULL){
		simple_suforder(t->left);
	}

	if(t->right!=NULL){
		simple_suforder(t->right);
	}

	printf("%d ",t->val);
}

