#include<iostream>
#include<string>
/*************************************
KMP算法
狄新凯
算法精髓：Partial Match Table
参考：http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html
**************************************/

/*通过计算返回子串T的next数组*/
void get_next(string T, int *next){
    int i,j;
    i = 1;
    j = 0;
    next[1] = 0;
    while(i < T.size()){
        //i从1遍历到T的长度，注意T.size()这个边界也是可以遍历到的。 
        ++i;
        ++j;
        next[i] = j;
    }
    else
        j = next[j];//若字符不相同，则j值回溯
    
}

/*返回子串T在主串S中第pos个字符之后的位置。若不存在，则函数返回值为0*/
int Index_KMP(string S, string T, int pos){
    int i = pos;//i用于主串S当前位置下标值，若pos不为1*/
                //则从pos位置开始匹配*/
                //j用于子串T中当前位置下标值
    int j = 1;
    int next[255];
    get_next(T, next);
    while(i <= S.size() && j <= T.size()){/*若i小于S的长度且j小于T的长度时，循环继续。*/
        if(j == 0 || S[i] == T[j]){//两字母相等则继续，相对于朴素算法增加了j=0判断。j = 0相当于一个哨兵。
                                   //j = 0,说明pattern中的第一个数和当前i指向文本的地方都不相等，则此时i直接后移。
                                   //从i后边的那个字符开始重新匹配。
            ++i;
            ++j
        }
        else{
            j = next[j];//j回退到合适的位置，i的值不回溯。
        }
    }
    if(j > T.size())
        return i-T[0];
    else
        return 0;
}

int main(){
    S = "idshfoiheirhggoogleshfeigehgihire";
    T = "google";
    int pos = Index_KMP(S, T, 4);
    cout<<pos<<endl;
}