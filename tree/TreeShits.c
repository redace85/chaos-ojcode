#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "TreeShits.h"

int main(){

	char t[]="{1,2,3,#,4,5,#,6,7,#,8}";
	struct TreeNode *r = make_tree(t);

	simple_inorder(r);
	puts("end of inorder");
	simple_preorder(r);
	puts("end of preorder");
	simple_suforder(r);
	puts("end of suforder");

	printf("T:%s\n",t);
}

