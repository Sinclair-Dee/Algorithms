 /*********************************************
  * 把一个包含n个正整数的序列划分成m个连续的子序列，每个整数刚好属于一个序列。
  * 设第i个序列的各数之和是S(i)。要求：让所有的S(i)的最大值尽量小。
  * 例如：序列1，2，3，2，5，4划分成3个序列的最优方案为123|25|4，其中S(1)=6,S(2)=7,S(3)=4。
  *  如果划分成12|32|54，则最大的S(i)=9，不是最优。其中n<10^6, 所有数之和不超过10^9
  * ******************************************/
  
  # include <iostream>
  using namespace std;
  # define MAXNUM = 1000000;
  int main(){
      int n,m;
      cin>>n>>m;
      cout<<"输入数字："<<endl;
      int num[MAXNUM];
      long long max = 0;
      for(int i = 0; i < n; i++){
          cin >>num[i];
          max += num[i];
      }
      long long min = max/m -1;
      i
      
      
      

      
      
      
  }
