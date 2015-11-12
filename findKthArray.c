#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int findKthLargest(int* nums, int numsSize, int k) {
	k=numsSize-k;
    
	int lo=0;
	int hi=numsSize-1;
	while(lo<hi){
		// partition-exchange 
		int i=lo+1;
		int j=hi;
		while(1){

			while(i<hi && nums[i]<=nums[lo]) ++i;
			while(j>lo && nums[j]>nums[lo]) --j;

			if(i>=j) break;

			nums[i]^=nums[j];
			nums[j]^=nums[i];
			nums[i]^=nums[j];
		}
		if(j!=lo){
			nums[lo]^=nums[j];
			nums[j]^=nums[lo];
			nums[lo]^=nums[j];
		}

		//reduce range
		if(j>k){
			hi=j-1;
		}else if(j<k){
			lo=j+1;
		}else{
			break;
		}
	}
	return nums[k];
}

int main(){
	//int a[] ={3,2,1,5,6,4};
	//int a[] ={3,3,3,3,3,3};
	int a[] ={-1,2,0};

	int ret = findKthLargest(a,3,3);
	printf("ret %d\n",ret);

	puts("end of app");
}

