#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int minSubArrayLen(int s, int* nums, int numsSize) {
	if(0==numsSize) return 0;

	int minlen=numsSize+1;
	int p1=0;
	int p2=0;
	int sum=0;
	do {
		sum+=nums[p2];
		++p2;
		while(sum>=s){
			int tl=p2-p1;
			minlen= minlen<tl? minlen : tl;

			sum-=nums[p1];
			++p1;
		}
	}while(p2<numsSize);
	return minlen==numsSize+1? 0 : minlen;
}

int main(){
	int a[] ={2,3,1,2,4,3};

	int ret = minSubArrayLen(7,a,6);
	printf("ret :%d\n",ret);

	puts("end of app");
}

