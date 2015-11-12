#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;

void backTrackingFun(int n,int k,int idx,vector<int> partial,vector<vector<int>> &ret);

vector<vector<int>> combinationSum3(int k, int n) {
	vector<vector<int>> ret;
	vector<int> partial;

	backTrackingFun(n,k,1,partial,ret);
	return ret;
}

void backTrackingFun(int n,int k,int idx,vector<int> partial,vector<vector<int>> &ret){
	if(1==k){
		if(idx<=n && n<10){
			partial.push_back(n);
			ret.push_back(partial);
		}
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

	auto ret=combinationSum3(3,9);

	for(auto x:ret){
		for(auto y:x){
			cout<<y<<",";
		}
		cout<<endl;
	}
}
