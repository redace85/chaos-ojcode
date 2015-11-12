#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int findMin(int* nums, int numsSize) {
	int p1=0;
	int p2=numsSize-1;

	while(p1<p2){
		if(nums[p1]<nums[p2]){
			return nums[p1];
		}

		int mid =(p1+p2)/2;
		if(nums[mid] >= nums[p1]){
			p1=mid+1;
		} else {
			p2=mid;
		}
	}

	return nums[p1];
}

int search(int* nums, int numsSize, int target) {
	int p1=0;
	int p2=numsSize-1;

	while(p1<p2){
		if(nums[p1]<nums[p2]){
			break;
		}

		int mid =(p1+p2)/2;
		if(nums[mid] >= nums[p1]){
			p1=mid+1;
		} else {
			p2=mid;
		}
	}

	int min=nums[p1];
	if(target==min) return p1;

	if(target<min){
		p2=p1-1;
		p1=0;
	} else {
		p2=numsSize-1;
	}
}

int main(){
	int a[] ={4,5,6,7,0,1,2};
	//int a[] ={1,1};

	int ret = findMin(a,7);
	printf("ret %d\n",ret);

	puts("end of app");
}

