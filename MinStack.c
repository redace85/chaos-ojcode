#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
	int ele;
	int cur_min;
} Unit;

typedef struct {
	int max;
	int cur;
	Unit *pdata;
} MinStack;

void minStackCreate(MinStack *stack, int maxSize) {
	stack->max=maxSize;
	stack->cur=0;
	stack->pdata=malloc(sizeof(Unit)*maxSize);
}

void minStackPush(MinStack *stack, int element) {
	int c=stack->cur;
	if(c==stack->max)
		return;
	Unit *pd=stack->pdata;
	pd[c].ele=element;
	if(0<c){
		int last_min=pd[c-1].cur_min;
		if(element < pd[last_min].ele){
			pd[c].cur_min=c;
		}else{
			pd[c].cur_min=last_min;
		}
	}else{
		pd[0].cur_min=0;
	}
	++(stack->cur);
}

void minStackPop(MinStack *stack) {
	if(stack->cur>0){
		--(stack->cur);
	}
}

int minStackTop(MinStack *stack) {
	int c=stack->cur;
	if(c>0){
		return stack->pdata[c-1].ele;
	}else{
		return 0;
	}
}

int minStackGetMin(MinStack *stack) {
	int c=stack->cur;
	if(c>0){
		int min=stack->pdata[c-1].cur_min;
		return stack->pdata[min].ele;
	}else{
		return 0;
	}
}

void minStackDestroy(MinStack *stack) {
	stack->max=0;
	stack->cur=0;
	if(0!=stack->pdata)
		free(stack->pdata);
}

int main(){
	MinStack ms;
	minStackCreate(&ms,100);
	minStackPush(&ms,22);
	minStackPush(&ms,842);
	minStackPush(&ms,99);

	int r=minStackTop(&ms);
	printf("r1 %d\n",r);

	minStackPop(&ms);
	r=minStackTop(&ms);
	printf("r2 %d\n",r);
	int m=minStackGetMin(&ms);
	printf("m %d\n",m);
	minStackDestroy(&ms);
}

