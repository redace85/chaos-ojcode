#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "ListShits.h"

struct ListNode *detectCycle(struct ListNode *head) {
	struct ListNode *fast=head;
	struct ListNode *slow=head;
    
	while(NULL!=fast &&	NULL!=fast->next){
		fast = fast->next->next;
		slow = slow->next;

		if(fast==slow){
			fast = head;
			while(fast != slow){
				fast = fast->next;
				slow = slow->next;
			}
			return fast;
		}
	}

	return NULL;
}

int main(){
	int vs[] ={3,2,0,-4};

	struct ListNode *h = make_list(vs,4);
	h->next->next->next = h->next;

	struct ListNode *bg = detectCycle(h);
	if(NULL!=bg){
		printf("begin %d\n",bg->val);
		puts("has cycle!");
	} else {
		puts("no cycle!");
	}

	puts("end of app");
}

