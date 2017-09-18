/*******************************************************************************
 * Cable master
 * 狄新凯 
 * 2016/09/18
 *******************************************************************************/
#include <iostream>
#define MAXNUM 10000
using namespace std;

int binarysearch(float num[], int n, int k,float min, float max){
  	float sum = 0;
  	float mid = (min + max)/2;
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
    int n, k;
    float sum = 0, num[MAXNUM];
    float max = 0.00, min = 0.00;
    cout<<"输入绳子数和段数："
    cin>>n>>k；
    cout<<"输入每个绳子的长度："
    for(int i = 0; i < n; i++){
        cin>>num[i];
        min = min < num[i] ? min : num[i];
        max += num[i];
    }
    max = max/m;
    min = min/m;
}