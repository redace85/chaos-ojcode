#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "AArray.h"

int A(int n, int k){
	int i=n-k+1;
	int ret=1;
	while(i<=n){
		ret*=i++;
	}
	return ret;
}

void backTrackingFun(int n,int k,int c,int idx,int *partial,int ***ret){
	if(c==k){
		int *p=malloc(sizeof(int)*k);
		if(NULL==p)
			exit(-1);
		memcpy(p,partial,sizeof(int)*k);

		(*ret)[0]=p;
		++(*ret);
		return;
	}

	int i=idx;
	for(;i<=n;++i){
		partial[c]=i;
		backTrackingFun(n,k,c+1,i+1,partial,ret);
	}
}

int** combine(int n, int k, int** columnSizes, int* returnSize) {
	// this is a math problem
	// C(n,k)=A(n,k)/k!
	*returnSize = A(n,k) / A(k,k);

	*columnSizes=malloc(sizeof(int)*(*returnSize));
	if(NULL==*columnSizes)
		exit(-1);
	int i=*returnSize-1;
	while(i>=0){
		(*columnSizes)[i--]=k;
	}
	int **ret=malloc(sizeof(int*)*(*returnSize));
	if(NULL==ret)
		exit(-1);
	int *partial=malloc(sizeof(int)*k);
	if(NULL==partial)
		exit(-1);

	int **retmp=ret;
	backTrackingFun(n,k,0,1,partial,&retmp);
	free(partial);

	return ret;
}

int main(){
	int *cs;
	int reSize;
	int **ret=combine(4,2,&cs,&reSize);

	printAA(ret,reSize,cs);
}
