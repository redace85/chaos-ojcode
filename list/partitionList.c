#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "ListShits.h"

struct ListNode *partition(struct ListNode *head, int x) {
	struct ListNode *p=head;
	struct ListNode *psmall=NULL;
	struct ListNode *p1=NULL;
	struct ListNode *plarge=NULL;
	struct ListNode *p2=NULL;
    
	while(NULL!=p){
		if(x<=p->val){
			//add 2 large
			if(NULL==plarge){
				plarge=p;
				p2=plarge;
			}else{
				p2->next=p;
				p2=p;
			}
		} else {
			//add 2 small
			if(NULL==psmall){
				psmall=p;
				p1=psmall;
			}else{
				p1->next=p;
				p1=p;
			}

		}
		p=p->next;
	}
	if(NULL!=p1 && NULL!=p2){
		head=psmall;
		p1->next=plarge;
		p2->next=NULL;
	}

	return head;
}

int main(){
	int a[] ={1,4,3,2,5,2};
	//int a[] ={1,4,3,2,5,2};

	struct ListNode *h = make_list(a,6);
	struct ListNode *af = partition(h,1);

	if(NULL==af){
		puts("NULL Head!");
	} else{
		print_list(af);
	}
	puts("end of app");
}

