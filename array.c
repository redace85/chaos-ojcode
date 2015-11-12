#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* reSdup1 {{{ */
int reSdup1(int a[],int n){
	int p1=0;
	int p2=0;

	int nn=n;
	while(p2<n){
		while(p2+1<n && a[p2]==a[p2+1]){
			--nn;
			++p2;
		}

		a[p1]=a[p2];
		++p1;
		++p2;
	}
	return nn;
}
/* }}} */

/* reSdup1 {{{ */
int reSdup6(int a[],int n){
	int p1=0;
	int p2=0;

	int nn=n;
	while(p2<n){

				do{
            bool bdup=false;
            while(p2+1<n && a[p2]==a[p2+1]){
                --nn;
                ++p2;
                bdup=true;
            }
            if(bdup){
                --nn;
                ++p2;
            }else{
                break;
            }
        }while(true);

        if(p2==n)
            break;

		a[p1]=a[p2];
		++p1;
		++p2;
	}
	return nn;
}
/* }}} */

int removeDuplicates(int A[], int n) {/*{{{*/
   	int p1=0;
	int p2=0;

	int nn=n;
	while(p2<n){
        int c=0;
		while(p2+1<n && A[p2]==A[p2+1]){
            if(c<1){
                A[p1]=A[p2];
                ++p1;
                ++p2;
                ++c;
            }else{
                --nn;
                ++p2;
            }
		}

		A[p1]=A[p2];
		++p1;
		++p2;
	}
	return nn; 
}/*}}}*/

int main(){
	int a[] ={1,1,3,4,6,9,9};
	int b[] ={1,1,1,1,3,8,9};

	int nl=reSdup1(a,7);
	int i;
	for(i=0;i<nl;++i){
		printf("%d,",a[i]);
	}

	puts("Remove Sorted Duplicated");
	int n2=removeDuplicates(b,7);
	for(i=0;i<n2;++i){
		printf("%d,",b[i]);
	}
	puts("end of app");
}

