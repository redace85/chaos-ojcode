#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int rob(int* nums, int numsSize) {
    switch(numsSize){
		case 0:
			return 0;
		case 1:
			return nums[0];
		case 2:
			return nums[0]>nums[1]? nums[0] : nums[1];
		default:
			break;
	}

	int dp1a = nums[0];
	int dp1b = nums[0]>nums[1]?nums[0]:nums[1];

	int dp2a = nums[1];
	int dp2b = nums[1]>nums[2]?nums[1]:nums[2];
	int c=3;

	while(c<numsSize){
		int temp = dp1b;
		int s = dp1a + nums[c-1];
		dp1b = s>dp1b ? s:dp1b; 
		dp1a = temp;

		temp = dp2b;
		s = dp2a + nums[c];
		dp2b = s>dp2b ? s:dp2b; 
		dp2a = temp;
		++c;
	}

	return dp1b>dp2b ? dp1b :dp2b;
}

int main(){
	int arr[] ={9,5};
	int ret=rob(arr,2);

	printf("%d,",ret);

	puts("end of app");
}

