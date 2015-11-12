#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int singleNumber(int* nums, int numsSize) {
    int ones = 0, twos = 0;

	int i=0;
	while(i<numsSize){
        ones=(ones^nums[i])&~twos;
        twos=(twos^nums[i])&~ones;
		++i;
    }
    return ones;
}

int main(){
	int a[] ={2,3,1,2,2,3,3};

	int ret = singleNumber(a,7);
	printf("ret :%d\n",ret);

	puts("end of app");
}

