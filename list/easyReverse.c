#include <stdio.h>
#include <stdlib.h>

#include "ListShits.h"

struct ListNode* reverseList(struct ListNode* head) {
	if(NULL==head) return head;

	struct ListNode *p=head;
	p=head->next;
	head->next=NULL;
	while(NULL!=p){
		struct ListNode *ptmp=p->next;
		p->next=head;
		head=p;
		p=ptmp;
	}
	return head;
}

struct ListNode* reverseListRe(struct ListNode* head) {
	if(NULL==head||NULL==head->next) return head;

	struct ListNode *p=head->next;
	head->next=NULL;
	struct ListNode *newhead=reverseListRe(p);
	p->next=head;

	return newhead;
}

int main(){
	int vs[] ={1,2,3,4,5};

	struct ListNode *h = make_list(vs,5);

	struct ListNode *af = reverseListRe(h);

	print_list(af);
	puts("end of app");
}

