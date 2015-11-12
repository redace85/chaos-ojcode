#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPowerOfTwo(int n) {
	return n>0 && 0==(n&(n-1));
}

int main(){
	if(isPowerOfTwo(1)){
		puts("true");
	}else{
		puts("false");
	}
	puts("end of app");
}

