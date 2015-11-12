#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
   if(0==numsSize) return 0; 

   int *ret=malloc(numsSize*sizeof(int));
   *returnSize=numsSize;

   int i=0;
   while(i<numsSize){
	   ret[i]=1;
	   ++i;
   }

   i=1;
   int right=1;
   int left=1;
   while(i<numsSize){
	   left*=nums[i-1];
	   ret[i]*=left;

	   right*=nums[numsSize-i];
	   ret[numsSize-i-1]*=right;
	   ++i;
   }

   return ret;
}

int main(){
	int a[]={1,2,3,4};
	int n=0;

	int *b=productExceptSelf(a,4,&n);
	
	int i=0;
	while(i<n){
		printf("%d\n",b[i]);
		++i;
	}
	puts("end of app");
}

