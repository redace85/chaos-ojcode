#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int countPrimes(int n) {
	bool *pb = calloc(n-1,sizeof(bool));
    
	int ret_c=0;
	// idx 0 represent 2
	int idx=0;
	int pend=n-2;
	while(idx<pend){
		if(0==pb[idx]){
			++ret_c;
			int op=idx;
			while(op<pend){
				pb[op]=1;
				op+=(idx+2);
			}
		} 
		++idx;
	}
	free(pb);
	return ret_c;
}

int countPrimesTry(int n) {
	size_t block_size = (n-1)*sizeof(bool);
	bool pb[190]={0};
    
	//memset(pb,0,block_size);
	int ret_c=0;
	// idx 0 represent 2
	int idx=0;
	int pend=n-2;
	while(idx<pend){
		if(0==pb[idx]){
			++ret_c;
			int op=idx;
			while(op<pend){
				pb[op]=1;
				op+=(idx+2);
			}
		} 
		++idx;
	}
	return ret_c;
}

int main(){
	int ret = countPrimes(120);
	printf("ret :%d\n",ret);
	puts("end of app");
}

