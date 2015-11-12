#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void reverseWords(char *s) {
	char *p=s;
	char *f=s;
	while(0!=*p){
		while(isspace(*p)) ++p;
		if(0==*p) break;

		// forward word
		char *wh=f;
		while(0!=isgraph(*p)){
			if(f!=p) *f=*p;
			++f;
			++p;
		}
		char *wt=f-1;

		while(wh<wt){
			char t=*wh;
			*wh=*wt;
			*wt=t;
			++wh;
			--wt;
		}
		// space
		if(f!=p) *f=32;
		if(0!=*p){
			++f;
			++p;
		}
	}

	if(f!=p) *f=0;

	// trailing space
	if(isspace(*(f-1))) *(--f)=0;
	--f;

	//reverse the hole string
	while(s<f){
		char t=*s;
		*s=*f;
		*f=t;
		++s;
		--f;
	}
}

int main(){
	//printf("space:%d\n",' ');
	char a[]=" the  sky is  blue  ";
	//char a[]="1 ";

	reverseWords(a);
	printf("be:%sEnd\n",a);

	puts("end of app");
}

