#include <iostream>
#include <array>
using namespace std;
public void merge(int [] array, int low, int mid, int high){
    int i = low; //i位第一段序列的下标
    int j = mid + 1;//j 是第二段序列的下标
    int k = 0;//临时存放合并序列的下标
    int [] array2 = new int[high - low +1] //array2是临时合并序列
    //扫描第一段和第二段序列，直到有一个扫描结束
    while(i < mid && j <= high){
        //判断第一段和第二段取出的数哪个更小，将其存入合并序列，并继续向下扫描
        if(array[i] <= array[j]){
            array2[k] = array[i];
            i++;
            k++
        }else{
            array2[k] = array[j];
            j++;
            k++;
        }
    }
    //第一段和第二段哪一段没有扫描完就将其全部复制到合并序列中
    while(i < mid){
        array2[k] = array[i] ;
        i++;
        k++;
    }
    while(j < high){
        array2[k] = array[j];
        j++;
        k++;
        
    }
    for(int k = 0, i = low; i <= high; i++, k++){
        array[i] = array2[k];
    }
}
