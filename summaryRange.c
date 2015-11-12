#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char** summaryRanges(int* nums, int numsSize, int* returnSize) {
	*returnSize=0;
	if(0==numsSize){
		return 0;
	}
	char **ret=malloc(sizeof(char*)*numsSize);
	char buff[265];
	int p1=0;
	int p2=1;
	while(p1<numsSize){
		while(p2<numsSize && nums[p2-1]==nums[p2]-1) ++p2;

		if(p1 < p2-1){
			int isp=sprintf(buff,"%d->%d",nums[p1],nums[p2-1]);
			char *m=malloc(sizeof(char)*(isp+1));
			ret[*returnSize]=strcpy(m,buff);
			++(*returnSize);
		}else{
			int isp=sprintf(buff,"%d",nums[p1]);
			printf("n:%d,isp:%d\n",nums[p1],isp);
			char *m=malloc(sizeof(char)*(isp+1));
			ret[*returnSize]=strcpy(m,buff);
			++(*returnSize);
		}
		p1=p2;
		++p2;
	}
	return ret;
}

int main(){
	//int a[]={0,1,2,4,5,7};
	int a[]={0,2,3,4};
	int rs;
	char** res=summaryRanges(a,4,&rs);

	int i=0;
	while(i<rs){
		printf("%sE\n",res[i]);
		++i;
	}

	puts("end of app");
}
