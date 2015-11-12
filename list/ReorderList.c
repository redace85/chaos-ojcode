#include <stdio.h>
#include <stdlib.h>

#include "ListShits.h"

void reorderList(struct ListNode *head) {
	if(NULL==head) return;

	struct ListNode *pslow=head;
	struct ListNode *pfast=head->next;

	while(NULL!=pfast && NULL!=pfast->next){
		pslow=pslow->next;
		pfast=pfast->next->next;
	}
	struct ListNode *pt=pslow->next;
	pslow->next=NULL;
	pslow=pt;

	//reverse last half
	struct ListNode *ptail=NULL;
	while(NULL!=pslow){
		pt=pslow->next;
		if(NULL==ptail){
			ptail=pslow;
			ptail->next=NULL;
		}else{
			pslow->next=ptail;
			ptail=pslow;
		}
		pslow=pt;
	}
	//cant separate
	if(NULL==ptail) return;

	//merge
	pslow=head;
	while(NULL!=ptail){
		pt=ptail->next;
		ptail->next=pslow->next;
		pslow->next=ptail;
		pslow=ptail->next;
		ptail=pt;
	}
}

int main(){
	int vs[] ={1,2,3,4,5,6};

	struct ListNode *h = make_list(vs,6);
	//print_list(h);
	reorderList(h);

	print_list(h);
	puts("end of app");
}

