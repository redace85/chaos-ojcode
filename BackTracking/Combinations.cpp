#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;

void backTrackingFun(int n,int k,int idx,vector<int> &partial,vector<vector<int>> &ret);

vector<vector<int>> combine(int n, int k) {
	vector<vector<int>> ret;
	vector<int> partial;

	backTrackingFun(n,k,1,partial,ret);
	return ret;	
}

void backTrackingFun(int n,int k,int idx,vector<int> &partial,vector<vector<int>> &ret){
	if(0==k){
		ret.push_back(partial);
		return;
	}

	for(auto i=idx;i<=n;++i){
		partial.push_back(i);
		backTrackingFun(n,k-1,i+1,partial,ret);
		partial.pop_back();
	}
}

int main(){
	auto ret=combine(4,2);

	for(auto x:ret){
		for(auto y:x){
			cout<<y<<",";
		}
		cout<<endl;
	}
}
