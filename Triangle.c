#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int minimumTotal(int **triangle, int numRows) {
	if(0>=numRows) return 0;
	int *res=malloc(sizeof(int)*numRows);
	if(NULL==res)
		exit(-1);
	res[0]=triangle[0][0];

	int i=1;
	while(i<numRows){
		int *cur=triangle[i];
		//last one 
		res[i]=res[i-1]+cur[i];
		int j=i-1;
		while(j>0){
			res[j]=(res[j]<res[j-1])?res[j]:res[j-1];
			res[j]+=cur[j];
			--j;
		}
		//first one
		res[0]+=cur[0];
		++i;
	}

	int ret=res[0];
	i=1;
	while(i<numRows){
		if(ret>res[i])
			ret=res[i];
		++i;
	}
	free(res);
	return ret;
}

int main(){
	int *pd[4] ={0};
	int a[]={2};
	int b[]={3,4};
	int c[]={6,5,7};
	int d[]={4,1,8,3};
	pd[0]=a;
	pd[1]=b;
	pd[2]=c;
	pd[3]=d;

	int ret = minimumTotal(pd,4);

	printf("ret: %d,",ret);
	puts("end of app");
}

