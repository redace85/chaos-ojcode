#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "AArray.h"

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
	if(0==matrixRowSize) return false;

	int p1=0;
	int p2=matrixRowSize;
	bool bfound=false;
	int cur;
	// locate row
	while(p1<p2){
		cur=(p1+p2)/2;
		if(target<matrix[cur][0]){
			p2=cur;
			continue;
		}
		if(target>matrix[cur][matrixColSize-1]){
			p1=cur+1;
			continue;
		}
		//found
		bfound=true;
		break;
	}

	if(!bfound) return false;

	int *arr=matrix[cur];
	p1=0;
	p2=matrixColSize;
	while(p1<p2){
		cur=(p1+p2)/2;
		if(target==arr[cur]){
			return true;
		}
		if(target<arr[cur]){
			p2=cur;
		}else{
			p1=cur+1;
		}
	}
    
	return false;
}

bool searchMatrix2(int** matrix, int matrixRowSize, int matrixColSize, int target) {
	if(0==matrixRowSize) return false;

	int p1=0;
	int p2=matrixRowSize*matrixColSize;

	while(p1<p2){
		int mid = (p1+p2)/2;
		int v=matrix[mid/matrixColSize][mid%matrixColSize];
		if(v==target)
			return true;

		if(target>v){
			p1=mid+1;
		}else{
			p2=mid;
		}
	}
	return false;
}

int main(){
	int a[] ={1,3,5,7};
	int b[] ={10,11,16,20};
	int c[] ={23,30,34,50};
	int *aa[]={a,b,c};
	int si[]={4,4,4};
	printAA(aa,3,si);

	if( searchMatrix2(aa,3,4,3) ){
		puts("found");
	}else{
		puts("No found");
	}

	puts("end of app");
}

