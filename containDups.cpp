#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
	unordered_set<int> uset;
	for(auto n: nums){
		auto r=uset.insert(n);
		if(!r.second)
			return true;
	}
	return false;
}

bool containsNearbyDuplicate(vector<int>& nums, int k) {
	unordered_set<int> uset;
	int size = nums.size();
	int w=0;
	for(int i=0;i<size;++i){
		if(i-w>k){
			uset.erase(nums[w++]);
		}
		auto r=uset.insert(nums[i]);
		if(!r.second)
			return true;
	}
	return false;
}

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
	map<int,int> map;
	int size = nums.size();
	int w=0;
	for(int i=0;i<size;++i){
		if(i-w>k){
			map.erase(nums[w]);
			++w;
		}
		int v=nums[i];
		auto it=map.lower_bound(v-t);

		if(map.end()!=it && abs(it->first-v)<=t){
			return true;
		}
		map[v]=i;
	}
	return false;
}

int main(){
	vector<int> v;
	v.push_back(888);
	v.push_back(87);
	v.push_back(12);
	v.push_back(87);
	v.push_back(121);
	v.push_back(87);

	auto ret=containsNearbyDuplicate(v,1);
	if(ret){
		cout<<"There Dups"<<endl;
	}else{
		cout<<"There NO Dups"<<endl;
	}
}
