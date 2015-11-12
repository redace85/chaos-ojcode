#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> ret;
	vector<int> partial;

	return ret;
}

void backTrackingFun(vector<int> nums,vector<int> partial,vector<vector<int>> &ret){
	if(nums.empty()){
		ret.push_back(partial);
		return;
	}

	for(auto i=idx;i<10;++i){
		if(i<n){
			partial.push_back(i);
			backTrackingFun(n-i,k-1,i+1,partial,ret);
			partial.pop_back();
		}else{
			break;
		}
	}
}

int main(){
	vector<int> some;
	some.push_back(1);
	some.push_back(2);
	some.push_back(3);

	auto ret=permute(some);

	for(auto x:ret){
		for(auto y:x){
			cout<<y<<",";
		}
		cout<<endl;
	}
}

