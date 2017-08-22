/************************************
//狄新凯
//最大子序列和问题
//参考：http://conw.net/archives/9/
//最后一种优化，单独一个文件
//时间复杂度O(N),空间复杂度O(1)
//同时也是代码量最小的一种算法！！！
************************************/
#include<iostream>
using namespace std;

int main(){
    int N, num;
    int sum, max, lmin;
    cout<<"输入数组大小:";  cin>>N;
    cout<<"输入数组:"<<endl; cin>>sum;
    max = 0;
    lmin = sum < 0 ? sum : 0; 
    for(int i = 1; i < N; i++){
        cin>>num;
        sum += num;//到i的累积
        max = sum - lmin > max ? sum - lmin : max;//更新最大序列和 
        lmin = sum < lmin ? sum : lmin;
    }
    cout<<max;
    return 0;
}