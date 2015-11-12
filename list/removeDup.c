#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "ListShits.h"

struct ListNode *deleteDuplicates(struct ListNode *head) {
	if(NULL == head) return head;

	struct ListNode *p=head; 
	
	while(NULL != p->next){
		if(p->val == p->next->val){
			struct ListNode *del =p->next;
			p->next = p->next->next;
			free(del);
		} else{
			p=p->next;
		}
	}

	return head;
}

struct ListNode *deleteDuplicates2(struct ListNode *head) {
	if(NULL == head) return head;

	struct ListNode *p=head; 
	struct ListNode *pre=NULL; 
	
	bool bdup =false;
	while(NULL != p->next){
		if(p->val == p->next->val){
			struct ListNode *del =p->next;
			p->next = p->next->next;
			free(del);
			bdup = true;
		} else{
			if(bdup){
				if(NULL==pre){
					head=p->next;
					free(p);
					p=head;
				}else{
					pre->next=p->next;
					free(p);
					p=pre->next;
				}
				bdup=false;
			} else {
				pre=p;
				p=p->next;
			}
		}
	}
	// end needs to be deleted
	if(bdup){
		if(NULL!=pre){
			pre->next=NULL;
		} else{
			head=NULL;
		}
		free(p);
	}

	return head;
}

struct ListNode* removeElements(struct ListNode* head, int val) {
   	if(NULL == head) return head;

	struct ListNode *p=head; 
	struct ListNode *pre=NULL; 
	
	while(NULL != p){
		if(p->val == val){
			struct ListNode *del =p;
			p=p->next;
			if(NULL!=pre){
				pre->next=p;
			}else{
				head=p;
			}
			free(del);
		} else{
			pre=p;
			p=p->next;
		}
	}

	return head;
}

int main(){
	//int vs[] ={1,1};
	//int vs[] ={1,2,3,4,4,5,5};
	int vs[] ={1,2,6,3,4,5,5};

	struct ListNode *h = make_list(vs,7);
	struct ListNode *af = removeElements(h,5);

	if(NULL==af){
		puts("NULL Head!");
	} else{
		print_list(af);
	}
	puts("end of app");
}

