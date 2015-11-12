#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <cstdint>

using namespace std;

//Definition for singly-linked list.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode *make_list(int a[], int n){
	if(n==0) return 0;

	auto h = new RandomListNode(a[0]);
	auto k =h;
	for(int i=1; i<n; ++i){
		k->next = new RandomListNode(a[i]);
		k = k->next;
	}
	return h;
}

void print_list(const RandomListNode *p){

	while(p!=0){
		cout <<p->label <<endl;
		p=p->next;
	}
}

RandomListNode *copyRandomList(RandomListNode *head) {
	auto p=head;
	RandomListNode *new_head=NULL;
	RandomListNode *new_pre=NULL;
	unordered_map<uintptr_t,uintptr_t> node_map;
	vector<RandomListNode **> ptrs_vec;
	while(NULL!=p){
		auto pt = new RandomListNode(p->label);
		node_map[uintptr_t(p)]=uintptr_t(pt);
		if(NULL!=p->random){
			pt->random=p->random;
			ptrs_vec.push_back(&(pt->random));
		}

		if(NULL!=new_head){
			new_pre->next=pt;
			new_pre=pt;
		}else{
			new_head=pt;
			new_pre=pt;
		}

		p=p->next;
	}

	if(!ptrs_vec.empty()){
		for (auto it=ptrs_vec.begin(); it!=ptrs_vec.end(); ++it){
			*(*it)=(RandomListNode *)node_map.at(uintptr_t(*(*it)));
		}
	}

	return new_head;
}

int main(){
	int vs[] ={1,-1,81,-43,1,91,9};

	auto h = make_list(vs,7);
	h->next->next->random=h;

	auto c = copyRandomList(h);
	print_list(c);

	int l =c->next->next->random->label;
	cout<<"r"<<l<<endl;
}

