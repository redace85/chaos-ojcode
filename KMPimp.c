#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include <string.h>

int kmp_search(char *needle, char *haystack) {
	if(NULL==haystack || NULL==needle)
		return -1;

	int nl=strlen(needle);
	int *failtable= (int *)malloc(nl*sizeof(int));
	if(NULL==failtable)
		exit(-1);

	//fail table
	char *p=needle;
	char *pn=needle+1;
	failtable[0]=-1;
	int pos=0;
	while(0!=*pn){
		failtable[pn-needle]=pos;
		if(*p==*pn){
			++pos;
			++p;
		}else{
			pos=0;
			p=needle;
		}
		++pn;
	}

	//finding
	p=haystack;
	pn=needle;
	int ret=-1;
	while(0!=*p){
		while(*p==*pn && 0!=*p){
			++p;
			++pn;
		}
		if(0==*pn){
			//found
			ret=(p-haystack)-nl;
			break;
		}
		//no chance to find
		if(0==*p)
			break;

		//differ
		pos=failtable[pn-needle];
		if(-1==pos){
			++p;
		}else{
			pn=needle+pos;
		}
	}

	free(failtable);

	return ret;
}

int main(){
	char h[] = "ABC ABCDAB ABCDABCDABDE";

	int ret = kmp_search("ABCDABD",h);

	printf("ret:%d\n",ret);
}

	/*int i;
	for(i=0;i<nl;++i){
		printf("%d,",failtable[i]);
	}
	return 0;
	*/
