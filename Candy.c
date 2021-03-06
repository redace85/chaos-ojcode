#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int candy(int* ratings, int ratingsSize) {
    if(1>=ratingsSize) return ratingsSize;

    int p=1;
    int descend_len=0;
    int cur_candy=1;
	int tot=1;
	bool bhandle=false;
    int desc_candy;

    while(p<ratingsSize){
		if(ratings[p-1]>ratings[p]){
			//descending
			++descend_len;
			--cur_candy;
			if(p==ratingsSize-1){
				bhandle=true;
				desc_candy=cur_candy;
			}
		}else{
			// from descending
			if(0!=descend_len){
				bhandle=true;
				desc_candy=cur_candy;
				cur_candy=1;
			}

			if(ratings[p-1]==ratings[p]){
				cur_candy=1;
			}else{
				//ascending
				++cur_candy;
			}
		}
		tot+=cur_candy;

		//handle descending length
		if(bhandle){
			int h=desc_candy-1;
			if(0!=h){
				if(0<h){
					tot-=descend_len*h;
				}else{
					tot-=(descend_len+1)*h;
				}
			}

			descend_len=0;
			bhandle=false;
		}
		++p;
    }

	return tot;
}

int main(){
	int a[] ={1,1,3,4,6,9,9};

	int ret=candy(a,7);

    printf("ret: %d",ret);
	puts("end of app");
}

