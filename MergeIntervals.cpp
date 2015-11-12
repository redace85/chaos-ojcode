#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
    vector<Interval> v;
	if(!intervals.empty()){
	    // sort first
		sort(intervals.begin(),intervals.end(),cmp);
		auto it = intervals.begin();
		int s=it->start;
		int e=it->end;
		++it;
		while(it!=intervals.end()){
			int st=it->start;
			int et=it->end;
			if(st<=e){
				if(st<s){
					s=st;
				}
				if(et>e){
					e=et;
				}
			} else {
				v.push_back(Interval(s,e));
				s=st;
				e=et;
			}
			++it;
		}
		v.push_back(Interval(s,e));
	}
	return v;
    }
	bool cmp (const Interval &i,const Interval &j){
	return (i.start<j.start);
	}
};
int main(){

	vector<Interval> v;
	v.push_back(Interval(1,4));
	v.push_back(Interval(0,0));
	//v.push_back(Interval(8,10));
	//v.push_back(Interval(15,18));
	Solution so;
	auto ret = merge(v);

	for(auto x:ret){
		cout<<"s:"<<x.start<<" e:"<<x.end<<endl;
	}
}

