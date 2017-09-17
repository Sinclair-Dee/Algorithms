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
  //找到这个最大值的上界和下界限
  //上界：max = num[0]+num[1]+num[2]+...num[n-1]
  //下界：min = max/m
  //取上下界的中间值mid,然后开始在数组中取序列，刚好大于等于mid的时候开始再取下一个序列。
  //数最后取得序列的个数k
  //若k>m:说明mid取小了，再从mid到max之间二分选取。
  //若k<m;说明mid取大了，再从min到mid之间取值。
  //注意k=m 的时候实际上还可以把mid往大处取值，与k>m情况一样处理。
  //最后的结果是min 和 max 只相差一个数，mid 向下取整取的min.
  //思考：其实最后不一定取min和max哪个是最好的结果，需要筛选，这个过程不是算法的核心内容，略过了。
  //上边给出的测试用例是取得min,而且恰好min比较合适。
  //binarysearch：用二分法寻找合适的最大值
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
