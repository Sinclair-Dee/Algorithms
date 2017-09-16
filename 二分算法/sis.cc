 /*********************************************
  * 把一个包含n个正整数的序列划分成m个连续的子序列，每个整数刚好属于一个序列。
  * 设第i个序列的各数之和是S(i)。要求：让所有的S(i)的最大值尽量小。
  * 例如：序列1，2，3，2，5，4划分成3个序列的最优方案为123|25|4，其中S(1)=6,S(2)=7,S(3)=4。
  *  如果划分成12|32|54，则最大的S(i)=9，不是最优。其中n < 1000 , 所有数之和不超过65536
  * ******************************************/
  
  # include <iostream>
  using namespace std;
  # define MAXNUM  1000
  
  //算法思想，二分查找
  int binarysearch(int num[], int n, int m,int min, int max){
  	int sum = 0;
  	int k = 0;
  	int mid = (min + max)/2;
  	if(mid == min) return mid;//经验证，为向下取整
  	for(int i = 0; i < n; i++){
  		sum += num[i];
  		if(sum >= mid){//刚好大于等于mid的时候开始取下一个序列
  			sum = 0;
  			k += 1;
  		}
  	}
  	k += 1;
  	sum = 0; 
  	if(k <= m){
  		max = mid; 
  		sum = binarysearch(num, n, m, min, max);
  	}
  	if(k > m){
  		min = mid;
  		sum = binarysearch(num, n, m, min, max);
  	}
  	return sum;
  }
  int main(){
	  int n,m;
	  cout<<"输入m和n:";
	  cin>>n>>m;
	  cout<<"输入数字："<<endl;
	  int num[MAXNUM];
	  int max = 0;
	  for(int i = 0; i < n; i++){
		  cin >>num[i];
		  max += num[i];
	  }
	  int min = max/m;
	  int sum = binarysearch(num, n, m, min, max);
	  cout<<"每次取序列刚好大于"<<sum<<"时。"<<endl;
  }
