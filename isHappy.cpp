#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

bool isHappy(int n) {
	if(0==n) return false;

	int num=n; 
	unordered_set<int> set;
	while(true){
		int val=0;
		while(0!=num){
			int p=num%10;
			val+=p*p;
			num/=10;
		}
		num=val;
		if(1==num){
			return true;
		} else {
			auto ret_pair=set.insert(num);
			if(!ret_pair.second){
				//cycle
				return false;
			}
		}
	}
}

int main(){
	if(isHappy(15)){
		cout<<"is Happy"<<endl;
	}else{
		cout<<"no Happy"<<endl;
	}
}

