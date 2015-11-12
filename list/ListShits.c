#include <stdio.h>
#include <stdlib.h>

#include "ListShits.h"

int main(){
	int vs[] ={1,-1,81,-43,1,91,9};

	struct ListNode *h = make_list(vs,7);
	print_list(h);
	free_list(h);
	puts("end of app");
}

