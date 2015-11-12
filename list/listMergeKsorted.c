#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "ListShits.h"

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
        if(NULL == l1)
			return l2;
		if(NULL == l2)
			return l1;

		struct ListNode *h;
		struct ListNode *fp;
		struct ListNode *sp;
		if(l1->val < l2->val){
			h = l1;
			sp = l2;
		} else {
			h = l2;
			sp = l1;
		}
		fp = h;

		while(NULL!=sp){
			int t = sp->val;
			struct ListNode *fpn = fp->next;
			while(NULL!=fpn && fpn->val <= t ){
				fp = fpn;
				fpn = fpn->next;
			}

			fp->next = sp;
			fp = sp;
			sp = fpn;
		}

		return h;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
	if(0==listsSize) return 0;
	if(1==listsSize) return lists[0];

	while(1!=listsSize){
		int offset=0;
		int newSize=0;
		while(listsSize>1){
			struct ListNode *p=mergeTwoLists(lists[offset],lists[listsSize-1+offset]);
			lists[offset]=p;
			++newSize;
			++offset;
			listsSize-=2;
		}
		// odd number
		if(1==listsSize){
			++newSize;
		}
		listsSize=newSize;
	}
	return lists[0];
}

int main(){
	int a[] ={3,6,9};
	int b[] ={1,2,4,5};
	int c[] ={7,10,13};
	int d[] ={8,11,12};
	struct ListNode * ll[4]={0};

	ll[0] =make_list(a,3);
	ll[1] =make_list(b,4);
	ll[2] =make_list(c,3);
	ll[3] =make_list(d,3);

	struct ListNode *af = mergeKLists(ll,4);
	//struct ListNode *af = mergeTwoLists(h,h2);

	if(NULL==af){
		puts("NULL Head!");
	} else{
		print_list(af);
	}
	puts("end of app");
}

