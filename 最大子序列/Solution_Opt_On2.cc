
/************************************
//狄新凯
//最大子序列和问题
//参考：http://conw.net/archives/9/
//最后一种优化，单独一个文件
************************************/
#include<iostream>
using namespace std;
//N是数组长度，num是待计算的数组，放在全局区是因为可以开很大的数组
int N, num[1024];
int main(){
    cout<<"输入数组大小:";
    cin>>N;
    cout<<"输入数组:"<<endl;
    for(int i = 0; i <N; i++){
        cin>>num[i];
    }
    //int ans = vio_solution();
    //int ans = vio_opti_solution();
    //int ans = DandC_solution();
    //int ans = DP_solution();
    int ans = Opti_On1();
    //int ans = Opti_On2();
    cout<<ans;
    return 0;
}