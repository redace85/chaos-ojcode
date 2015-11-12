#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;

void backTrackingFun(int lefts, int n, string r, vector<string> &ret);

vector<string> generateParenthesis(int n) {
	vector<string> ret;

	backTrackingFun(n,n,"",ret);
	return ret;
}

void backTrackingFun(int lefts, int rights, string r, vector<string> &ret){
	if(0==lefts && 0==rights){
		ret.push_back(r);
		return;
	}

	if(lefts>0){
		backTrackingFun(lefts-1,rights,r+'(',ret);
	}

	if(rights>lefts){
		backTrackingFun(lefts,rights-1,r+')',ret);
	}
}

int main(){
	auto ret=generateParenthesis(3);

	for(auto x:ret){
		cout<< x <<endl;
	}
}
