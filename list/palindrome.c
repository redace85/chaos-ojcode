#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "ListShits.h"

bool isPalindrome(struct ListNode* head) {
	if(!head || !head->next) return true;

	struct ListNode *pslow=head;
	struct ListNode *pfast=head->next;
	struct ListNode *pp=NULL;
	struct ListNode *pt=NULL;
	struct ListNode *ph=NULL;

	//reverse the first half
	while(pfast && pfast->next){
		pt=pslow->next;
		pslow->next=pp;
		pp=pslow;
		pslow=pt;
		pfast=pfast->next->next;
	}
	//odd or even
	pt=pslow->next;
	if(pfast){
		pslow->next=pp;
		head=pslow;
		ph=pt;
	}else{
		head=pp;
		ph=pslow;
	}
	//restore and judge
	bool res=true;
	while(head){
		if(res && head->val!=pt->val){
			res=false;
		}
		pp=head->next;
		head->next=ph;
		ph=head;
		head=pp;
		pt=pt->next;
	}
	return res;
}

int main(){
	int vs[] ={1,2,3,3,2,1};

	struct ListNode *h = make_list(vs,6);

	if(isPalindrome(h)){
		puts("Palindrome!");
	}

	print_list(h);
	puts("end of app");
}

