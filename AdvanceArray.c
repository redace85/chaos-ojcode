#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize) {
	int n=1;
	//permutation stuff
	*returnSize = pow(2,numsSize);
	int **ret=(int **)malloc(sizeof(uintptr_t)*(*returnSize));
	*columnSizes=(int *)malloc(sizeof(uintptr_t)*(*returnSize));

	while(n<numsSize){

		++n;
	}
    
	return 0;
}

void printAA(int *a[], int s,int *cs){
	puts("------ start ------");
	int i=0;
	while(i<s){
		int *sa=a[i];

		int j=0;
		int end = cs[i];
		while(j<end){
			printf("%d,",sa[j]);
			++j;
		}
		printf("end line %d\n",i);

		++i;
	}
	puts("------ stop ------");
}

int main(){
	int a[] ={1,2,3};

	int s;
	int *cs;
	int **subs = subsets(a,3,&cs,&s);
	printAA(subs,s,cs);

	puts("end of app");
}

