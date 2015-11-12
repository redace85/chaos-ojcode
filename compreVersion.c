#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int compareVersion(char *version1, char *version2){
	char *p1=version1;
	char *p2=version2;
	// trim meanless zero
	while(*p1=='0') ++p1;
	while(*p2=='0') ++p2;

	while(0!=*p1||0!=*p2){
		int sv1=0;
		int sv2=0;

		while(isdigit(*p1)){
			sv1 = sv1*10+(int)(*p1-48);
			++p1;
		}
		while(isdigit(*p2)){
			sv2=sv2*10+(int)(*p2-48);
			++p2;
		}

		if(sv1!=sv2){
			return sv1>sv2? 1:-1;
		}

		if('.'==*p1) ++p1;
		if('.'==*p2) ++p2;
	}

	return 0;
}

int main(){

	int ret = compareVersion("1.1","1.01");
	if(0==ret){
		puts("pass1");
	}

	ret = compareVersion("1.2","1.10");
	if(-1==ret){
		puts("pass2");
	}

	ret = compareVersion("1.1","1.10");
	if(-1==ret){
		puts("pass3");
	}

	puts("end of app");
}

