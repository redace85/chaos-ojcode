#include <iostream>
#include <string>

using namespace std;

string addBinary(string a, string b) {
	string *l;
	string *s;
	if( a.length()>=b.length() ){
		l = &a;
		s = &b;
	} else {
		l = &b;
		s = &a;
	}

	auto it = (*s).end();
	auto lit = (*l).end();
	auto begin = (*s).begin();
	auto lb = (*l).begin();
	int advence = 0;

	while(it>begin|| (1==advence && lit>lb) ){
		int s_num=0;
		if(it!=begin){
			--it;
			s_num = (*it-48);
		}
		--lit;
		int res = s_num+(*lit-48)+advence;

		switch(res){
			case 1:
				*lit = '1';
				advence =0;
				break;
			case 2:
				*lit = '0';
				advence = 1;
				break;
			case 3:
				*lit = '1';
				advence = 1;
				break;
			default:
				advence =0;
				break;
		}
	}

	if(1==advence){
		(*l).insert(lb,'1');
	}

	return *l;
}

int main(){

	string a("1010");
	string b("1011");
	auto ret = addBinary(b,a);

	cout<< ret <<endl;
}
