#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void quick_sort(int* arr,int n) {
    if(n<=1)
        return;
    int z = arr[0];

    int *p1=arr+1;
    int *p2=arr+n-1;
    while(p1!=p2){
        if(*p1>z){
            int t=*p2;
            *p2=*p1;
            --p2;
            *p1=t;
        }else{
            ++p1;
        }
    }

    //move z
    if(*p1>z){
        --p1;
        arr[0]=*p1;
        *p1=z;
    }else{
        ++p2;
        arr[0]=*p1;
        *p1=z;
    }

    // recursive
    quick_sort(arr,(p1-arr)+1);
    quick_sort(p2,n-(p2-arr));
}

int main(){
    int a[]={8,3,4,6,7,99,1,2,5};
    int n = 9;
    for(int i=0;i<n;++i){
        printf("%d ",a[i]);
    }
    printf("\n");
    quick_sort(a,n);
    for(int i=0;i<n;++i){
        printf("%d ",a[i]);
    }
}

