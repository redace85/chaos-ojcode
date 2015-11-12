#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isIsomorphic(char* s, char* t) {
	int ms[0x7f]={0};
	int mt[0x7f]={0};
	char *ps=s;
	char *pt=t;
	while(0!=*ps){
		int i = *ps;
		int j = *pt;
		if(0!=ms[i]){
			if(ms[i]!=j)
				return false;
		} else {
			if(0!=mt[j])
				return false;
			ms[i]=j;
			mt[j]=i;
		}

		++pt;
		++ps;
	}
	return true;
}

// printf("i:%d\n",i);
//printf("mi:%c\n",*pt);
int main(){
	char s[] ="13";
	char t[] ="27";

	if(isIsomorphic(s,t)){
		puts("isomorphic!");
	} else{
		puts("No isomorphic!");
	}
	puts("end of app");
}

