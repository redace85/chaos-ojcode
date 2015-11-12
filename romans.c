#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int romanToInt(char* s) {
	if(NULL==s) return 0;
	int tail=strlen(s)-1;
    
	int res=0;
	while(tail>=0){
		switch(s[tail]){
			case 'I':
				res += (res>=5? -1:1);
				break;
			case 'V':
				res += 5;
				break;
			case 'X':
				res += 10*(res>=50? -1:1);
				break;
			case 'L':
				res += 50;
				break;
			case 'C':
				res += 100*(res>=500? -1:1);
				break;
			case 'D':
				res += 500;
				break;
			case 'M':
				res += 1000;
				break;
		}
		--tail;
	}
	return res;
}

char* intToRoman(int num) {
	// max length would be 15+1,reprents 3888
	char buf[16]={0};
	char *p=buf;
	int ele=1000;

	while(ele>0){
		int digit=num/ele;
		num%=ele;
		if(digit>0){
			switch(ele){
				case 1000:
					while(digit>0){
						*p++='M';
						--digit;
					}
					break;
				default:{
					char one;
					char five;
					char ten;
					switch(ele){
						case 100:
							one='C';
							five='D';
							ten='M';
							break;
						case 10:
							one='X';
							five='L';
							ten='C';
							break;
						case 1:
							one='I';
							five='V';
							ten='X';
							break;
					}
					switch(digit){
						case 9:
							*p++=one;
							*p++=ten;
							break;
						case 4:
							*p++=one;
							*p++=five;
							break;
						default:
							if(digit>=5){
								*p++=five;
								digit-=5;
							}
							while(digit>0){
								*p++=one;
								--digit;
							}
							break;
					}

						}
				break;//end of default
			}
		}
		ele/=10;
	}

	char *ret=malloc(sizeof(char)*(p-buf+1));
	strcpy(ret,buf);

	return ret;
}

int main(){
	//int ret = romanToInt("MMMXLV");
	//printf("ret:%d",ret);

	printf("Roman:%s\n",intToRoman(1999));
	puts("end of app");
}

