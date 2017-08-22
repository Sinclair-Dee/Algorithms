/*************************************
KMP算法
狄新凯
算法精髓：Partial Match Table
参考：
(1)大话数据结构
(2)http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html
**************************************/

#include<iostream>
#include<string>
using namespace std;

/*通过计算返回子串T的next数组*/
//与大话数据结构不同,该程序的next[]满足的数学公式：
//next[j] = -1        j=0
//             max{k|0<k<j-1且”p0 ... pk-1“ == ”pj-k ... pj-1}当此集合不为空的时候
//              0        其他情况
//
int get_next(string T, int *next){
    int i, j;
    i = 0;
    j = -1;
    next[0] = -1;
    while(i < T.size()-1){//i从0遍历到T的长度，注意T.size()这个边界也是可以遍历到的，应专门做一下考虑。
        if(j == -1 || T[i] == T[j]){
            ++i;
            ++j;
            next[i] = j;            
        }
        else
            j = next[j];//若字符不相同，则j值回溯
    }
    return 0;
}

/*返回子串T在主串S中第pos个字符之后的位置。若不存在，则函数返回值为S.size()*/
int Index_KMP(string S, string T, int pos){
    int i = pos;//i用于主串S当前位置下标值，若pos不为1*/
                //则从pos位置开始匹配*/
                //j用于子串T中当前位置下标值
    int j = -1;
    int next[255];
    get_next(T, next);
    while(j == -1 || (i < S.size() && j < T.size())){/*若i小于S的长度且j小于T的长度时，循环继续。*/
													//后来又加入了j=-1这个条件，因为发现 j=-1时 j<T.size()这个条件不符合!!
        if(j == -1 || S[i] == T[j]){//两字母相等则继续，相对于朴素算法增加了j=-1判断。j = -1相当于一个哨兵。
									//大话数据结构将数组的第一个数下标都设为1，哨兵为0,这样在实践中发现会造成数组越界。所以本程序改成了-1.
                                   //j = -1,说明pattern中的第一个数和当前i指向文本的地方都不相等，则此时i直接后移。
                                   //从i后边的那个字符开始重新匹配。
            ++i;
            ++j;
        }
        else{
            j = next[j];//j回退到合适的位置，i的值不回溯。
        }
    }
    if(j == T.size())
        return i-T.size();
    else
        return S.size();
}

int main(){
    string S = "idshfoiheirhggoogleshfeigehgihire";
    string T = "google";
    int pos = Index_KMP(S, T, 4);
    cout<<pos<<endl;
}