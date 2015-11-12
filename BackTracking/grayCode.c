#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* grayCode(int n, int* returnSize) {
	*returnSize= 1<<n; 
	int *ret=malloc(sizeof(int)*(*returnSize));
	if(NULL==ret)
		exit(-1);

	ret[0]=0;
	int i=1;
	for(;i<(*returnSize);++i)
		ret[i]=i^(i>>1);
	return ret;
}

int main(){
	//int a[] ={1,1,3,4,6,9,9};
	int *some;

	int *ret=grayCode(0,some);

	printf("some:sh%d\n",*some);

	int i=0;
	while(i< *some){
		printf("%x,",ret[i]);
		++i;
	}

	puts("end of app");
}

