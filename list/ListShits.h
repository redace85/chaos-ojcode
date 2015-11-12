//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *make_list(int a[], int n){
	if(n==0) return 0;

	struct ListNode *h = malloc(sizeof(struct ListNode));
	h->val = a[0];
	struct ListNode *k =h;
	int i;
	for(i=1; i<n; ++i){
		k->next = malloc(sizeof(struct ListNode));
		k->next->val = a[i];
		k = k->next;
	}
	k->next=0;
	return h;
}

void free_list(const struct ListNode *p){
	while(p!=0){
		struct ListNode *pt=p->next;
		free((void *)p);
		p=pt;
	}
}

void print_list(const struct ListNode *p){
	if(NULL==p) return;

	while(p!=0){
		printf("%d ", p->val);
		p=p->next;
	}
}

