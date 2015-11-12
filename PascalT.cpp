#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > generate(int numRows) {
	vector<vector<int> > res;

	for(int i=1;i<=numRows;++i){
		vector<int> row(i);
		for(int j=0;j<i;++j){
			if(0==j||j==i-1){
				row[j]=1;
			}else{
				auto rec=res[i-2];
				row[j] = rec[j-1]+rec[j];
			}
		}
		res.push_back(row);
	}

	return res;
}

vector<int> getRow(int rowIndex) {
	vector<int> res(rowIndex+1);

	res[0]=1;
	for(int i=1;i<=rowIndex;++i){
		int n;
		if(0==i%2){
			n =i/2+1;
		} else {
			n=(i+1)/2;
		}
		for(int j=1;j<n;++j){
			int tar=res[j];
			int t = j;
			bool badd=true;
			while(t>0){
				tar= badd? tar+res[t-1]:tar-res[t-1];
				badd = !badd;
				--t;
			}
			res[j]=tar;
			res[i-j]=tar;
		}
		res[i]=1;
	}

	return res;
}

int main(){
	auto ret = generate(3);

	for(auto i :ret){
		for(auto j:i){
			cout<<j<<",";
		}
		cout<<endl;
	}

	cout<<"RowNum"<<endl;
	auto row=getRow(4);
	for(auto k:row){
		cout<<k<<",";
	}
	cout<<endl;

	cout<<"end off app"<<endl;
}
