/*******************************************************************************
 * 排序算法
 * 狄新凯
 * 参考：大话数据结构
 * 2017/09/04
 ******************************************************************************/
 #include<iostream>
 using namespace std;
 #define MAXSIZE 100
 typedef struct
{
 int r[MAXSIZE + 1]; //用于存储要排序的数组，r[0]用作哨兵或者临时变量
 int length;       //用于记录顺序标的长度
} SqList;

//交换l中数组r的下标为i和j的值
void swap(SqList *L, int i, int j){
  L->r[i] = L->r[i] + L->r[j];
  L->r[j] = L->r[i] - L->r[j];
  L->r[i] = L->r[i] - L->r[j];
 
}

/*******************************************************************************
 * 冒泡算法
 * 冒泡算法(Bubble Sort)是一种交换算法，他的基本思想是：两两比较相邻记录的关键字，
 * 如果反序则交换，直到没有反序的记录为止。
 * bubblesort0()冒泡排序初级版
 * bubblesort1()冒泡排序
 * bubblesort2()冒泡排序改进版
 * 冒泡排序时间复杂度：
 *    最好情况为序列为正序，根据改进版，只有n-1次比较。
 *    最差的情况为逆序，要做n*(n-1)/2 次比较和等量的交换，时间复杂度为O(n2)。
 ******************************************************************************/
void bubblesort0(SqList *L){//i和它后面的数相比较
  for(int i = 1; i < L->length; i++)
    for(int j = i + 1; j < L->length; j++){
      if(L->r[i] > L->r[j]){
        swap(L,i,j);
      }
    }
}//这种算法的效率非常低
void bubblesort1(SqList *L){
  for(int i = 1; i < L->length-1; i++)
    for(int j = L->length-1; j > i; j--){//注意 j 从后往前循环
      if(L->r[j] < L->r[j - 1])//若前者大于后者,后者滚到前边来。
        swap(L, j, j-1);//注意是 j 和 j-1互换
    }
}
//改进的冒泡排序，对于发现已经有序的的序列，及时停止循环
void bubblesort2(SqList *L){
  bool flag = true;
  for(int i = 1; i < L->length-1 && flag; i++){
    flag = false;
    for(int j = L->length-1; j > i; j--){
      if(L->r[j] < L->r[j - 1]){//若前者大于后者,后者滚到前边来。
        swap(L, j, j-1); 
        flag = true; //只要在一个内循环中出现交换，则说明i后边的数还没有排好
                     //若一次交换都没发生，说明i后边的数都排好了，不需要再进行外部循环，直接退出。
      }
    }    
  }

}


/*******************************************************************************
 * 简单选择排序
 * 选择排序的基本思想是每一趟在n-i+1(i=1,2,3，....,n-1)个记录中选取关键字最小的
 * 记录作为有序数列的第i个记录。
 * 时间复杂度分析：
 *    最好和最差的情况需要比较的次数是一样的，第i趟排序需要进行n-i次关键字的比较，共n(n-1)/2次
 *    最好的交换次数是0次，最差的交换次数是n-1次
 *    最终的时间复杂度为O(n2)
 ******************************************************************************/
 void SelectSort(SqList *L){
   int min;
   for(int i = 1; i < L->length; i++){
     min = i;
     for(int j = i+1; j < L->length; j++){
       if(L->r[j] < L->r[min]){
         min = j;//记录最小记录的下标
       }
     }
     if(min != i){
       swap(L,i,min);
     }
   }
 }
 
/*******************************************************************************
 * 简单插入排序
 * 直接插入排序(Straight Insertion Sort)的基本操作是将一个记录插入已经排好序的有
 * 序表中，从而得到一个新的、记录+1的有序表
 * 算法复杂度分析:
 *    最好的情况: 假如序列本身就是正序，那么只要L->r[i]和L->r[i-1]进行比较，共比较n-1次，无移动
 *    最坏的情况：假如序列本身是逆序，那么需要比较和移动的数量级都是n2,时间复杂度O(n2).
 ******************************************************************************/
 void InserSort(SqList *L){
   for(int i = 2; i < L->length; i++){//目的是将L->r[i]插到合适的位置
     if(L->r[i] < L->r[i-1]){
       L->r[0] = L->r[i];//设置哨兵，把待插入的数赋值给哨兵。
       int j;//注意j的作用域。
       for(j = i-1; L->r[j] > L->r[0]; j--){
         L->r[j + 1] = L->r[j];//哨兵比当前记录小时记录右移
       }
       L->r[j + 1] = L->r[0];//把哨兵放在合适的位置。
     }
   }
 }
 
 /*******************************************************************************
 * 希尔排序
 * 将原本有大量记录数的记录进行分组。分割成若干个子序列，此时每个子序列待排序的记录个数就比较小了。
 * 在这些子序列内分别进行直接插入排序，当整个子序列都基本有序的时候，注意只是基本有序时，再对全体记录进行一次插入排序
 * 若要实现基本有序，需要采用跳跃分割的策略：
 *        将相聚某个“增量”的记录组成一个子序列，这样才能保证在子序列内分别进行直接插入排序后的结果是基本有序，而不是局部有序。
 * 
 ******************************************************************************/
 void ShellSort(SqList *L){
   
 }
 
/*******************************************************************************
 * TEST main
 * 使用固定的数组r
 ******************************************************************************/
int main(){
  SqList *L = NULL;
  L = (SqList*)malloc(sizeof(SqList));//不要忘了申请空间
  L->length = 10; //数组大小
  int num[] = {0,4,8,1,2,9,3,5,7,6};
  for(int i = 0; i < L->length; i++){
    L->r[i] = num[i]; 
  }
  //bubblesort0(L);
  //bubblesort1(L);
  //bubblesort2(L);
  //SelectSort(L);
  InserSort(L);
  cout<<"排序后的结果:"<<endl;
  for(int i = 1; i < L->length; i++){
  cout<<L->r[i]<<" ";
  }
  return 0;
 }