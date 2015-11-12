#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include <string.h>

int myAtoi(char *str) {
   int l = strlen(str); 
   int i=0;
   while(i<l && isspace(str[i])) ++i;

   int sign =1;
   if(i<l && '-'==str[i]){
	   sign =-1;
	   ++i;
   } else if(i<l && '+'==str[i]){
	   ++i;
   }
   int num =0;
   int maxD10 = INT_MAX/10;
   while(i<l && isdigit(str[i])){
	   int d = (int)(str[i]-48);
	   if(num >maxD10 || (num==maxD10 && d>7 )){
		   printf("sign :%d\n",sign);
		   return 1==sign ? INT_MAX :INT_MIN;
	   }
	   num = num*10+d;
	   ++i;
   }
   return num * sign;
}

int reverse(int x) {
   int res=0; 

   int maxD10 = INT_MAX/10;
   while(0!=x){
	   if(abs(res)>maxD10){
		   return 0;
	   }
	   res = res*10+x%10;
	   x/=10;
   }
   return res;
}

int main(){
	//printf("space:%d\n",INT_MAX);
	char a[]="    -2929dblue";
	//char a[] = "2147483648";

	int ret = myAtoi(a);
	printf("ret:%d\n",ret);
	int rev = reverse(ret);
	printf("rev:%d\n",rev);
	puts("end of app");
}

