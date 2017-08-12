//pseudo-code
//set min[i] equal to infinity for all of i
//min[0] = 0;
//For i = 1 to s
//  s[i] = s[i-1] +1; 
//  For j = 0 to N-1
//      IF(V[j]<=i) and min[i-v[j]] + 1 <min[i]
//          min[i] = min[i - v[j]] +1;
//output min[s]

#include <iostream>
#include<vector>
#define COINS 3
using namespace std;
int main(){
	int s;
	cin>>s;
	vector <int> min;
	min.resize(s+1);
	//状态：min[i]
	//状态方程：min[i] = Min{min[i-vj] +1}
	//其中vj分别为1元，3元,5元和7元的硬币
	int v[COINS] = {1,3,5};
	//两层循环实现状态方程
	min[0] = 0;
	for(int i = 1; i<s+1;i++){
	    min[i] = min[i-1]+1;
	    for(int j = 1;j<COINS;j++){
	        if(i >= v[j])
	            min[i] = min[i] < min[i-v[j]] + 1? min[i] : min[i-v[j]]+1;
	    }
	}
//内循环展开的写法
//	{
//		min[i] = min[i-1] + 1;
//		if(i>2) min[i] = min[i] < min[i-3]+1? min[i] :  min[i-3]+1;
//		if(i>4) min[i] = min[i] < min[i-5]+1? min[i] :  min[i-5]+1;
//	}

	cout<<"最少"<<min[s]<<"个硬币";
	return 0;
}
