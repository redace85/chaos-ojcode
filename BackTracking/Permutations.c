#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int** permute(int* nums, int numsSize, int* returnSize) {

	int **ret=malloc(sizeof(int*));
	return 0;
}

void backTrackingFun(int n,int **ret){
	if(1==k){
		if(idx<=n && n<10){
			partial.push_back(n);
			ret.push_back(partial);
		}
		return;
	}

	for(auto i=idx;i<10;++i){
		if(i<n){
			partial.push_back(i);
			backTrackingFun(n-i,k-1,i+1,partial,ret);
			partial.pop_back();
		}else{
			break;
		}
	}
}

void printAA(int *a[], int s,int se){
	puts("------ start ------");
	int i=0;
	while(i<s){
		int *sa=a[i];

		int j=0;
		int end = se;
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
	int some[]={1,2,3};
	int size=3;
	int rs;

	int **ret=permute(some,size,&rs);
	printAA(ret,rs,size);

	puts("end of app");
}

