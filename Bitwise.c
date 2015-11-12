#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int rangeBitwiseAnd(int m, int n) {
	int c=0;
	while(m!=n){
		m>>=1;
		n>>=1;
		++c;
	}
	return n<<c;
}

int main(){
	int ret =rangeBitwiseAnd(5,7);

	printf("ret:%d\n",ret);
	puts("end of app");
}

