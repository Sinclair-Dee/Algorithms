/*******************************************************************************
 * 排序算法(非降序)
 * 狄新凯
 * 参考：数据结构与算法分析(C++描述)
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
  bubblesort1(L);
  cout<<"排序后的结果:"<<endl;
  for(int i = 1; i < L->length; i++){
  cout<<L->r[i]<<" ";
  }
  return 0;
 }