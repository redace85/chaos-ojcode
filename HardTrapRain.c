#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/* vim: set expandtab tabstop=4 shiftwidth=4 foldmethod=marker: */

/* reSdup1 {{{ */
int trap(int* height,int heightSize){
    int highest=0;
    int i;
    for(i=1;i<heightSize;++i){
        if(height[highest]<height[i]){
            highest=i;
        }
    }

	int water=0;
    int p=1;
    int edge=0;
    while(p<highest){
        if(height[edge]>height[p]){
            water+=height[edge]-height[p];
        } else {
            edge=p;
        }
        ++p;
    }

    p=heightSize-2;
    edge=heightSize-1;
    while(p>highest){
        if(height[edge]>height[p]){
            water+=height[edge]-height[p];
        } else {
            edge=p;
        }
        --p;
    }
	return water;
}
/* }}} */

int main(){
	int a[] ={0,1,0,2,1,0,1,3,2,1,2,1};

	int ret=trap(a,12);
    printf("ret:%d,",ret);

	puts("end of app");
}

