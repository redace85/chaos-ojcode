#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
	int key;
	int val;
	D_Node *prev;
	D_Node *next;
} D_Node;

typedef struct {
	D_Node *pdata;
	D_Node *cur;
} D_Ring;

D_Ring g_str_dring;

void lruCacheInit(int capacity) {
    
}

void lruCacheFree() {
    
}

int lruCacheGet(int key) {
    
}
    
void lruCacheSet(int key, int value) {
    
}

int main(){
}

