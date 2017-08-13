//pseudo-code
//set d[i] equal to infinity for all of i
//len = 1;
//For i = 1 to s
//  d[i] = 1; 
//  For j = 0 to i-1
//      IF(A[j]<=A[i]) and d[j] + 1 > d[i]
//          d[i] = d[j] +1;
//  IF(d[i] > len)
//      len = d[i]
//RETURN len
//node:内外循环都要有个初始化。
#include <iostream>
#define NUM 8
using namespace std;

int lis(int A[], int n){
    int *d = new int[n];
    int len =1;
    for(int i=0; i<n; i++){
        d[i] = 1;
        for(int j=1; j<i; j++){
            if(A[j]<=A[i] && d[j] +1>d[i])
                d[i] = d[j] + 1;
        }
        if(d[i]>len) len = d[i];
    }
    //delete和new是相对应的，申请的地址要及时释放。
    //注意申请的数组的释放方式
    delete[] d;
    return len;
}

int main(){
    int A[] = {
        5, 3, 7, 8, 6, 7,6,9
    };
    cout<<lis(A, NUM)<<endl;
    return 0;
}