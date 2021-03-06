/***************************************
 * 问题描述：
 * 求对于长度为 N的数组A，求子数组的和接近0的子数组，要求时间复杂度O(NlogN)
 * 算法流程:
 * s1: 申请同样长度的空间sum[0...N-1],sum[i]是A的前i项和。
 *  Trick: 定义sum[-1] = 0;
 * 算法：
 * 对sum[0..N-1]排序，然后计算sum相邻元素的差，最小值记为min1
 * min1: 在A中任意取两个集合，各自元素的和求差的最小值。
 * 因为sum[-1] = 0,sum[0..N-1]的绝对值记为min2。(考虑负数和最最小值的影响)
 * min2:A的前k个元素的和的绝对值的最小值
 * 比较min1和min2的更小值，即为所求。
 * status: haven't done
 * **************************************/
#include<iostream>
using namespace std;

int main(){
int A[1024];
int sum[1024];
int N;
for(int i = 0; i < N; i++){
    for(int)
}
}
 
