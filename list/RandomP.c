#include <stdio.h>
#include <stdlib.h>

//Definition for singly-linked list.
struct RandomListNode {
    int label;
    struct RandomListNode *next;
    struct RandomListNode *random;
};

struct RandomListNode *make_list(int a[], int n){
	if(n==0) return 0;

	struct RandomListNode *h = (struct RandomListNode *)malloc(sizeof(struct RandomListNode));
	h->label=a[0];
	struct RandomListNode *k =h;
	int i;
	for(i=1; i<n; ++i){
		k->next = malloc(sizeof(struct RandomListNode));
		k->next->label = a[i];
		k = k->next;
	}
	k->next=0;
	return h;
}

void print_list(const struct RandomListNode *p){
	while(p!=0){
		printf("%d ", p->label);
		p=p->next;
	}
}

struct RandomListNode *copyRandomList(struct RandomListNode *head) {
	if(NULL==head) return head;

	struct RandomListNode *p=head;
	struct RandomListNode *pt;
	//copy nodes in place
	while(NULL!=p){
		pt=p->next;
		p->next=malloc(sizeof(struct RandomListNode));
		p->next->label=p->label;
		p->next->next=pt;
		p->next->random=NULL; 
		p=pt;
	};
	//fix random poniter
	p=head;
	while(NULL!=p){
		if(NULL!=p->random){
			p->next->random=p->random->next;
		}
		p=p->next->next;
	};
	//separate
	struct RandomListNode *copyed_head=NULL;
	p=head;
	while(NULL!=p){
		if(NULL!=copyed_head){
			pt->next=p->next;
			pt=pt->next;
		}else{
			copyed_head=p->next;
			pt=copyed_head;
		}
		p->next=p->next->next;
		p=p->next;
	};

	return copyed_head;
}

int main(){
	int vs[] ={6,-1,81,-43,1,91,9};

	struct RandomListNode *h = make_list(vs,7);
	h->next->next->random=h;

	struct RandomListNode *c = copyRandomList(h);
	print_list(c);

	int l =c->next->next->random->label;
	printf("r:%d\n",l);
}

