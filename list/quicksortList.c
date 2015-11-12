#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "ListShits.h"

struct ListNode *quickSortList(struct ListNode **head) {
	struct ListNode *p=*head;
	if(NULL==p || NULL==p->next) return p;

	int k=p->val;
	p=p->next;
	struct ListNode *pfront=NULL;
	struct ListNode *pf=NULL;
	struct ListNode *pback=NULL;
	struct ListNode *pb=NULL;
	while(NULL!=p){
		if(p->val<k){
			if(NULL!=pfront){
				pf->next=p;
				pf=pf->next;
			}else{
				pfront=p;
				pf=pfront;
			}
		}else{
			if(NULL!=pback){
				pb->next=p;
				pb=pb->next;
			}else{
				pback=p;
				pb=pback;
			}
		}
		p=p->next;
	}

	//front part
	if(NULL!=pf){
		pf->next=NULL;
		p=quickSortList(&pfront);
		pfront->next=*head;
	}else{
		p=*head;
	}
	(*head)->next=NULL;

	//back part
	if(NULL!=pb){
		pb->next=NULL;
		pb=quickSortList(&pback);
		(*head)->next=pb;
		*head=pback;
	}
	return p;
}

int compare (const void * a, const void * b){
  return ( (*(struct ListNode **)a)->val - (*(struct ListNode **)b)->val );
}

struct ListNode *sortList(struct ListNode *head) {
	if(NULL==head || NULL==head->next) return head;

	struct ListNode **arr;
	struct ListNode *p=head;
	int c=0;
	while(NULL!=p){
		++c;
		p=p->next;
	}

	arr=(struct ListNode **)malloc(sizeof(void *)*c);
	p=head;
	int i;
	for(i=0;i<c;++i){
		arr[i]=p;
		p=p->next;
	}
	qsort(arr,c,sizeof(void *),compare);

	for(i=0;i<c-1;++i)
		arr[i]->next=arr[i+1];

	arr[i]->next=NULL;
	return arr[0];
}

int main(){
	int a[] ={3,2,9,9,6,1,2};
	//int a[] ={1,4,3,2,5,2};

	struct ListNode *h = make_list(a,7);

	struct ListNode *af = sortList(h);

	if(NULL==af){
		puts("NULL Head!");
	} else{
		print_list(af);
	}
	printf("h:%d",h->val);
	puts("end of app");
}

