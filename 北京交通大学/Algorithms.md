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
    
    (5)Not in polynomial time: O(2exp(n)), O(n*exp(n)), O(n!)

### Polynomial-Time Algorithms
**Are some problems solvable in polynomial time?**
    
    Of course: many algorithms we’ve studied provide polynomial-time solutions to some problems

**Are all problems solvable in polynomial time?**
    
    No: Turing’s “Halting Problem” is not solvable by any computer, no matter how much time is given

Most problems that do not yield polynomial-time algorithms are either optimization or decision problems.

### Optimization/Decision Problems

- Optimization Problems

An optimization problem is one which asks, “What is the optimal solution to problem X?”

Examples:

    0-1 Knapsack
    Fractional Knapsack
    Minimum Spanning Tree
    
- Decision Problems

An decision problem is one with yes/no answer

Examples:

    Does a graph G have a MST of weight  W?
    
An optimization problem tries to find an optimal solution,A decision problem tries to answer a yes/no question

Many problems will have decision and optimization versions

Eg: 
    
    Traveling salesman problem(TSP 旅行商问题)
    optimization: find Hamiltonian cycle of minimum weight
    decision: is there a Hamiltonian cycle of weight  k
    
Some problems are decidable, but intractable: 

as they grow large, we are unable to solve them in reasonable time

**Is there a polynomial-time algorithm that solves the problem?**

### The class P

P: the class of decision problems that have polynomial-time deterministic algorithms.

That is, they are solvable in O(p(n)), where p(n) is a polynomial on n

A deterministic algorithm is (essentially) one that always computes the correct answer

Why polynomial?
    
    if not, very inefficient
    
    nice closure properties 
    
    the sum and composition of two polynomials are always polynomials too
    
Example:

    Sorting
    Fractional Knapsack
    MST 
    …



### The class NP

**NP: **the class of decision problems that are solvable in polynomial time on a nondeterministic machine (or with a nondeterministic algorithm)

A determinstic computer is what we know, and deterministic algorithms make decisions based on information.

A nondeterministic computer is one that can “guess” the right answer or solution, and nondeterministic algorithms produce an answer by a series of “correct guesses”

Think of a nondeterministic computer as a parallel machine that can freely spawn an infinite number of processes

Thus NP can also be thought of as the class of problems whose solutions can be verified in polynomial time 

**Note that NP stands for “Nondeterministic Polynomial-time” (非确定性多项式时间)**

*NP的特点：易验证(p时间)，但不可确定*

### P And NP Summary

- P = set of problems that can be solved in polynomial time
Examples: Fractional Knapsack, …

- NP = set of problems for which a solution can be verified in polynomial time

Examples: Fractional Knapsack,…, Hamiltonian Cycle, CNF SAT

Clearly：P属于NP

Open question: Does *P = NP?*

Most suspect not

An August 2010 claim of proof that P ≠ NP, by Vinay Deolalikar, researcher at HP Labs, Palo Alto, has flaws

P就是能在多项式时间内解决的问题，NP就是能在多项式时间验证答案正确与否的问题。
所以P是否等于NP实质上就是在问:如果对于一个问题我能在多项式时间内验证其答案的正确性，那么我是否能在多项式时间内解决它？

### Reduction

A problem R can be reduced to another problem Q if any instance of R can be rephrased to an instance of Q, the solution to which provides a solution to the instance of R

This rephrasing is called a transformation

Intuitively: If R reduces in polynomial time to Q, R is “no harder to solve” than Q

Example:

    lcm(m, n) = m * n / gcd(m, n), 
    lcm(m,n) problem is reduced to gcd(m, n) problem

### NP-hard 和 NP-complete

NP-hard：(比所有的NP问题都难的问题):任意np问题都可以在多项式时间内归约为该问题。归约的意思是为了解决问题A，先将问题A归约为另一个问题B，解决问题B同时也间接解决了问题A。
例如，停机问题。

NP-complete：满足两点：  

    1. 是NP hard的问题  
    2. 是NP问题
    
意思是任意的np问题可以在多项式时间内归约成该问题，但是该问题依然是np问题，所以归约成该问题也是徒劳的！
    
比较严谨的定义：

问题：对于一个包含由0和1组成的字符串集合S，以某个01字符串x作为输入，要求某个图灵机判断x在不在S里面。这里的图灵机可以先想象成平时我们用的计算机，S也可以被看成我们要解决的问题。注意我们的问题非常简单，就是要判断某个字符串x是否在某个集合S里面。

**下面是定义：**
    P：有一个图灵机在多项式时间内能够判断x是否在S里面
    
    NP：有一个图灵机M，如果某个字符串x在S里面，那么存在一个验证字符串u（注意这个u是针对这个x的，而且长度必须是x长度的多项式关系），M以x和u作为输入，能够验证x真的是在S里面。
    
    NP-hard：如果某个问题S是NP-hard，那么对于任意一个NP问题，我们都可以把这个NP问题在多项式时间之内转化为S，并且原问题的答案和转化后S的答案是相同的。也就是说只要我们解决了S，那么就解决了所有的NP问题。
    
    NP-complete：一个问题既是NP-hard，又在NP里面；也就是说   
        1. 解决了这个问题我们就解决了所有NP问题  
        2. 这个问题本身也是个NP问题

![np && p](http://owqf0jwjh.bkt.clouddn.com/npp.png)


**关于图灵机**
 
![图灵机](http://owqf0jwjh.bkt.clouddn.com/%E5%9B%BE%E7%89%87%201.png)

![通用图灵机](http://owqf0jwjh.bkt.clouddn.com/%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202017-09-23%20%E4%B8%8B%E5%8D%888.28.42.png)


# Enumeration

# Recursion and divide-conquer

# Dynamic planning

# Greedy Algorithms

# Search techniques


