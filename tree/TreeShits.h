//Definition for singly-linked list.
// and I implies a queue.
struct ListNode {
    struct TreeNode **pnode;
    struct ListNode *next;
};

//Definition for binary tree
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// inputs {2,#,4,842,3,#}
struct TreeNode * make_tree(const char *str){
	if(0==strlen(str)&&str[0]!='{')
		return 0;

	char *pbuff=(char *)malloc(sizeof(char)*(strlen(str)+1));
	strcpy(pbuff,str);
	char delimiter[]=" {},";
	// handle the root
	char *pos=strtok(pbuff,delimiter);
	if(NULL==pos){
		// no token
		return 0;
	}

	struct TreeNode *root=(struct TreeNode *)malloc(sizeof(struct TreeNode));
	root->val=atoi(pos);
	root->left=NULL;
	root->right=NULL;

	struct ListNode *phead=(struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *ptail=(struct ListNode *)malloc(sizeof(struct ListNode));
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
					struct TreeNode *point=(struct TreeNode *)malloc(sizeof(struct TreeNode));
					point->val=atoi(pos);
					point->left=NULL;
					point->right=NULL;
					(*p->pnode)=point;
					ptail->next=(struct ListNode *)malloc(sizeof(struct ListNode));
					ptail=ptail->next;
					ptail->pnode=&(point->left);

					ptail->next=(struct ListNode *)malloc(sizeof(struct ListNode));
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
	free(pbuff);
	return root;
}

void simple_inorder(struct TreeNode *t){
	if(t->left!=NULL){
		simple_inorder(t->left);
	}

	printf("%d ",t->val);

	if(t->right!=NULL){
		simple_inorder(t->right);
	}
}

void simple_preorder(struct TreeNode *t){
	printf("%d ",t->val);

	if(t->left!=NULL){
		simple_preorder(t->left);
	}

	if(t->right!=NULL){
		simple_preorder(t->right);
	}
}

void simple_suforder(struct TreeNode *t){
	if(t->left!=NULL){
		simple_suforder(t->left);
	}

	if(t->right!=NULL){
		simple_suforder(t->right);
	}

	printf("%d ",t->val);
}

