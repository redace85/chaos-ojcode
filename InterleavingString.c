#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isInterleave(char* s1, char* s2, char* s3) {
	int l3=strlen(s3);
	if(0==l3) return true;

	int l1=strlen(s1);
	int l2=strlen(s2);
	if(l3!=(l1+l2)) return false;

	char **p= &s1;
	// match length
	int ml=0;
	// position p,true means on s1
	bool pos_p=true;
	if(0==l1){
		p=&s2;
		ml=l3;
		pos_p=false;
	}

	while(*s3!=0){
		if(*s3==**p){
			if(pos_p){
				++ml;
				++(*p);
			}else{
				if(ml>0){
					--ml;
					++(*p);
				}else{
					p=&s1;
					pos_p=true;
				}
			}

			++s3;
		}else{
			if(pos_p){
			}else{
			}
		}
	}
    
	return true;
}

int main(){

	if(isInterleave("aabcc","dbbca","aadbbcbcac")){
		puts("True");
	}else{
		puts("False");
	}

	puts("end of app");
}

