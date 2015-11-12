#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;

void backTrackingFun(const string m[], const string &digits, string r, vector<string> &ret);

vector<string> letterCombinations(string digits) {
	vector<string> ret;
	if(0>=digits.size()) return ret;

	const string map[]={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	backTrackingFun(map,digits,"",ret);

	return ret;
}

void backTrackingFun(const string m[], const string &digits, string r, vector<string> &ret){
	int c=r.size();
	if(digits.size()==c){
		ret.push_back(r);
		return;
	}

	auto str = m[digits.at(c)-48];
	for(auto it=str.cbegin();it!=str.cend();++it){
		r.push_back(*it);
		backTrackingFun(m,digits,r,ret);
		r.pop_back();
	}
}

vector<string> lettercombinationsQQQ(string digits) {
	const string map[]={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	int len = digits.size();
	vector<string> ret;
	if(0>=len) return ret;

	stack<int> track;
	string partial(len,0);

	int current=0;
	while(current>=0){
		track.push(current);
		digits.at(current);
	}

	return ret;
}

int main(){
	auto ret=letterCombinationsQQQ("23");

	for(auto x:ret){
		cout<< x <<endl;
	}
}
