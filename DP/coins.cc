//pseudo-code
//set min[i] equal to infinity for all of i
//min[0] = 0;
//For i = 1 to s
//For
#include <iostream>
#include<vector>
using namespace std;
int main(){
	int s;
	cin>>s;
	vector <int> min;
	min.resize(s+1);
	//状态：min[i]
	//状态方程：min[i] = min{min[i-vj] +1}
	//其中vj分别为1元，3元和5元的硬币
	min[0] = 0;
	for(int i = 1; i<s+1;i++){
		min[i] = min[i-1] + 1;
		if(i>2) min[i] = min[i] < min[i-3]+1? min[i] :  min[i-3]+1;
		if(i>4) min[i] = min[i] < min[i-5]+1? min[i] :  min[i-5]+1;
	}
	cout<<"最少"<<min[s]<<"个硬币";
	return 0;
}