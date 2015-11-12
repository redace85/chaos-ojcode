#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;

void backTrackingFun(const vector<int>& candidates, int target,int idx,vector<int> partial,vector<vector<int>> &ret);

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	vector<vector<int>> ret;
	vector<int> partial;
	sort(candidates.begin(),candidates.end());
	backTrackingFun(candidates,target,0,partial,ret);

	return ret;
}

void backTrackingFun(const vector<int>& candidates, int target,int idx,vector<int> partial,vector<vector<int>> &ret){
	if(0==target){
		ret.push_back(partial);
		return;
	}

	int size=candidates.size();
	for(auto i=idx;i<size;++i){
		int v=candidates[i];
		// remove dups
		if(i>idx && v==candidates[i-1]) continue;

		if(v<=target){
			partial.push_back(v);
			backTrackingFun(candidates,target-v,i+1,partial,ret);
			partial.pop_back();
		}else{
			break;
		}
	}
}

int main(){
	vector<int> v({10,1,2,7,6,1,5});
	auto ret=combinationSum2(v,8);

	for(auto x:ret){
		for(auto y:x){
			cout<<y<<",";
		}
		cout<<endl;
	}
}
