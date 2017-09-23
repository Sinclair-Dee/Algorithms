# Introduction

### Computer and problem solving

- Fast calculation speed
- Large storage capacity

We need to design programs that can be executed by computers.The following skills are required:

- High level programming language---basic tool
- Data structure---basic element
- Algorithms analysis and design---key link

**Programs = Data Structure + Algorithms**

**Software = Programs + Documents**

Data structure: Array、Stack、Queue、Linked list、Tree、Graph、Heap、Hash、Standard template library with C
Java collections framework、.NET Framework....

### Reference

- Stanford “Design and Analysis of Algorithms” Part 1 & 2 on Coursera

- Princeton “Algorithms” Part 1 & 2 on Coursera (Opening)

- MIT  opencourse “Introduction of Algorithms”

- http://www.csie.ntnu.edu.tw/~u91029/ 

- http://algo-visualizer.jasonpark.me

Problems: 
- “Cracking the Coding Interview: 150 Programming Questions and Solutions”

- solutions：http://hawstein.com/posts/ctci-solutions-contents.html 

### BJTU ACM

http://acm.bjtu.edu.cn/  

### Assignment
Problem：given an array with N integer elements ，please find out the minimum absolute value of the difference between any two elements from the array. 
请求出给定N个整数构成的数组中两数之差（绝对值）的最小值。

Input：N，and the array with N elements

Output：the minimum absolute value of the difference

Input examle：

   5
   
   105 7 9 16 -31
   
Output example：

   2

**Definition of the function：** long  minDiff(int* iArray, int iNum)
思路1:先排序，排序之后扫描一趟相邻两数的差，找出其中最小值。


# Complexity of algorithms

- Space complexity
- Time complexity
- Space complexity for recursive function
- Space complexity for non-recursive function

### Complexity: The amount of computer resources needed to run the algorithm

Time complexity: Time resource needed

Space complexity: Space resource needed

Depends on the scale of the problem, input of algorithm and algorithm itself.

N: scale of problem    I: input of algorithm

T: time complexity     S: space complexity

T=T(N,I)和S=S(N,I)

**The main concern is time complexity**

Notation include：O(大o)、Ω、 Θ 

- O： f(N) and g(N) >=0，if there exist C and N0，when N >= N0, we can have f(N) <= C*g(N)，we say f(N)=O(g(N)).

The notation O()  implies an upper bound.  The lower the upper bound, the better the result.

- Ω: f(N) and g(N) >=0，if there exist C and N0，when N >= N0, we can have  f(N) >= C*g(N)，we say f(N)=Ω(g(N)) 

- Θ：f(N) =  Θ(g(N)) if and only if  f(N)=O(g(N)) && f(N)= Ω(g(N)) 。

Logarithmic order time complexity

- 2^x=n, x=log_2(n)
- Time complexity: O(log2n)

### Complexity analysis for recursive algorithms 
1） Analyze the structure of recursive program to determine the time complexity of each logical block.
    分析递归程序的结构，以确定每个逻辑块的时间复杂度
2）Construct recursive equation for complexity functions.
    构造复杂函数的递归方程。
3）Solve the recursive equation and its gradual order and express as O(.)
    求解递归方程及其渐变顺序，并表示为O()

### intractability
- Some problems are intractable:  as they grow large, we are unable to solve them in reasonable time
- What constitutes reasonable time? 

(1)Standard working definition: polynomial time
(2)On an input of size n the worst-case running time is O(n*exp(k)) for some constant k
(3)O(n2), O(n3), O(1), O(n lg n), O(2n), O(nn), O(n!)
(4)Polynomial time: O(n2), O(n3), O(1), O(nlogn) 
(5)Not in polynomial time: O(2n), O(nn), O(n!)

### Polynomial-Time Algorithms
**Are some problems solvable in polynomial time?**
- Of course: many algorithms we’ve studied provide polynomial-time solutions to some problems
**Are all problems solvable in polynomial time?**
- No: Turing’s “Halting Problem” is not solvable by any computer, no matter how much time is given

Most problems that do not yield polynomial-time algorithms are either optimization or decision problems.

# Enumeration

# Recursion and divide-conquer

# Dynamic planning

# Greedy Algorithms

# Search techniques


