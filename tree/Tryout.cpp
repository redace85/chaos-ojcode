#include <iostream>
#include <cstdlib>
#include <string>
#include <queue>

#include "TreeShits.h"

using namespace std;

int main(){

	string t("{1,2,3,#,4,5,#,6,7,#,8}");
	auto r = make_tree(t.c_str());

	simple_inorder(r);
	cout << endl;
	simple_preorder(r);
	cout << endl;
	simple_suforder(r);
	cout << endl;
}

