#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>

using namespace std;

vector<string> summaryRanges(vector<int>& nums){
	vector<string> ret;
	int n=nums.size();
	if(0==n)
		return ret;
	int p1=0;
	int p2=1;
	while(p1<n){
		while(p2<n && nums[p2-1]==nums[p2]-1) ++p2;

		if(p1 < p2-1){
			ret.push_back((to_string(nums[p1])+"->"+to_string(nums[p2-1])));
		}else{
			ret.push_back(to_string(nums[p1]));
		}
		p1=p2;
		++p2;
	}

	return ret;
}

int main(){
	vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(5);
	v.push_back(7);

	auto ret=summaryRanges(v);

	for(auto x:ret){
		cout<< x<<endl;
	}
	cout<<"end of app"<<endl;
}
