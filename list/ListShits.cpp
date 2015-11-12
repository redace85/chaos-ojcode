#include <iostream>
#include <string>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *make_list(int a[], int n){
	if(n==0) return 0;

	auto h = new ListNode(a[0]);
	auto k =h;
	for(int i=1; i<n; ++i){
		k->next = new ListNode(a[i]);
		k = k->next;
	}
	return h;
}

void print_list(const ListNode *p){

	while(p!=0){
		cout <<p->val <<endl;
		p=p->next;
	}
}

int main(){
	int vs[] ={1,-1,81,-43,1,91,9};

	auto h = make_list(vs,7);
	print_list(h);
}

