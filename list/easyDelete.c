#include <stdio.h>
#include <stdlib.h>

#include "ListShits.h"

void deleteNode(struct ListNode* node) {
    struct ListNode* tmp = node->next;
    *node = *(node->next);
    free(tmp);
}

int main(){
	int vs[] ={1,2,3,4,5};

	struct ListNode *h = make_list(vs,5);
	struct ListNode *n = h->next->next->next;

	deleteNode(n);
	print_list(h);
	puts("end of app");
}

