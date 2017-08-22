/************************************
//狄新凯
//最大子序列和问题
//参考：http://conw.net/archives/9/
************************************/
#include<iostream>
using namespace std;

//N是数组长度，num是待计算的数组，放在全局区是因为可以开很大的数组
int N, num[1024];
/***********************************
//暴力求解
//用两层循环枚举起点和终点
//第三层循环尝试了起点和终点之间所有的子数列，然后计算每个子数列的和。
//记录最大的结果
//这个算法的时间复杂度是O(N^3)
************************************/
int vio_solution(){
    int ans = num[0];
    for(int i = 0; i < N; i++)
        for(int j = 0; j <= i; j++){
            int sum = 0;
            for(int k = j; k <= i; k++)
                sum +=num[k];
            ans = ans > sum? ans : sum;
        }
    return ans;
}
//暴力求解的一个优化
//以空间换时间
int vio_opti_solution(){
    int ans = num[0];
    int sum[16384];
    sum[0] = 0;//作为一个边界
    //计算数组前缀和0-i
    for(int i = 0; i < N; i++){
        sum[i+1] = sum[i] + num[i];
    }
    //计算任意的j --> i
    int sumtemp = 0;
    for(int i = 1; i <= N; i++)
        for(int j = 0; j < i; j++){
            sumtemp = sum[i] - sum[j];
            ans = sumtemp > ans? sumtemp : ans;
    }
    return ans;
}
/************************************
//分治思想
首先，我们可以把整个数列平均分成左右两部分，答案则会在以下三种情况中：
1、所求数列完全包含在左半部分的数列中。
2、所求数列完全包含在右半部分的数列中。
3、所求数列刚好横跨分割点，即左右数列各占一部分。
前两种情况和大问题一样，只是规模小了些，如果三个子问题都能解决，那么答案就是三个结果的最大值。
主要研究一下第三种情况如何解决：
    要计算出：以分割点为起点向左的最大连续数列和、以分割点为起点向右的最大连续数列和，
    这两个结果的和就是第三种情况的答案。因为已知起点，所以这两个结果都能在O(N)的时间复杂度能算出来。
递归不断减小问题的规模，直到数列长度为1的时候，那答案就是数列中那个数字。
4、这个算法的时间复杂度是O(N*logN)的
************************************/
int solve(int left, int right){
    //处理特殊情况：数列长度为1时
    if(left == right)
        return num[left];
    //划分为两个规模更小的问题
    //递归
    int mid = (left + right) >> 1; //右移，表示除2
    int lans = solve(left, mid); //step1:左边一半的最大序列和
    int rans = solve(mid + 1, right); //step2:右边一半的最大序列和
    //step:计算跨越中间点时候的最大序列和
    //从跨越点向两边遍历，最终得出一个最大的值
    int lmax = num[mid];
    int sum = 0;
    for(int i = mid; i >= left; i--){
        sum += num[i];
        lmax = lmax > sum? lmax : sum;
    }
    int rmax = num[mid + 1];
    sum = 0;
    for(int i = mid+1; i <= right; i++){
        sum += num[i];
        rmax = rmax > sum? rmax : sum;
    }    
    int ans = lmax + rmax;//两边相加，第三种情况END
    
    //左最大，右最大和跨越中间点的最大三者作比较,返回较大值
    ans = ans >lans? ans : lans;
    ans = ans >rans? ans : rans;
    return ans;
}

int DandC_solution(){
    int ans = solve(0,N-1);//左右端点都会遍历到，所以不要越界。
    return ans;
}

/************************************
//动态规划
//状态：ans[i]--表示在第i个位置时含有num[i]的序列和。注意状态ans[i]不是最长的的序列和，但是能保证连续。
//对于位置i,有两种情况，如果加上num[i]，这个序列就小于0了，那么i处的序列和归零，这样可以重新开始算。
//若i有正面的影响，那么i处的ans[i] = ans[i-1] + num[i]。
//初始状态：ans[0] = 0;
//状态转移方程：ans[i] = max{anx[i-1]+num[i],0}
//算法的时间复杂度为：O(N)
************************************/
int DP_solution(){
    int ans[1024];
    ans[0] = 0; //这个地方应该为0,是一个前导，使得从num[0]开始算起。
    int max = num[0];
    for(int i = 1; i <= N; i++){
    ans[i] = ans[i-1] + num[i-1] > 0? ans[i-1] + num[i-1] : 0; //式子里的ans[i-1]最开始写成了ans[i]，注意，注意！
    max = max > ans[i]? max : ans[i];
    }
    return max;
}

/************************************
//其他两种优化
//Opti_On1；
//我们已知一个sum数组，sum[i]表示第1个数到第i个数的和，于是sum[j] - sum[i-1]表示第i个数到第j个数的和。
//Opti_On2；
//算法的时间复杂度为：O(N)
************************************/
int Opti_On1(){
    
}

int Opti_On2(){
    
}
/************************************/
//test main
//8
//-2 6 -1 5 4 -7 2 3
//ans = 14
/***********************************/
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
    //int ans = Opti_On1();
    //int ans = Opti_On2();
    //cout<<ans;
    return 0;
}
