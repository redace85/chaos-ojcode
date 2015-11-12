#include <stdio.h>
#include <stdlib.h>

#include "ListShits.h"

struct ListNode *reverseBetween(struct ListNode *head, int m, int n) {
	struct ListNode *p1=head;
	struct ListNode *pre=NULL;

	int bw=n-m;
	if(0==bw)
		return head;

	while(--m>0){
		pre=p1;
		p1=p1->next;
	}

	struct ListNode *p2=p1;
	while(bw-->0){
		p2=p2->next;
	}

	struct ListNode *pp1 = p2->next;
	struct ListNode *pn1 = p1->next;
	while(p1!=p2){
		p1->next = pp1;
		pp1=p1;
		p1=pn1;
		pn1=pn1->next;
	}
	p2->next = pp1;
	if(NULL!=pre){
		pre->next = p2;
	} else {
		head = p2;
	}

	return head;
}

int main(){
	int vs[] ={1,2,3,4,5};

	struct ListNode *h = make_list(vs,5);

	struct ListNode *af = reverseBetween(h,3,5);

	print_list(af);
	puts("end of app");
}

