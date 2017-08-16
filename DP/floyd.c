/****************************************/
//floyd算法
//算法思想：动态规划
//狄新凯
//2017/8/16
//status:compiled perfect!!!
/****************************************/

//必要头文件
#include "stdio.h"    
#include "stdlib.h"   
#include "math.h"  
#include "time.h"
//必要宏定义
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 1000 /* 最大顶点数，应由用户定义，此处为1000 */
#define INFINITY 65535 //最大权值

typedef int VertexType; //顶点类型
typedef int EdgeType;    //边(权值)类型

//与迪杰斯特拉算法不同，因为是求任意两点的最短路径和权重和，所以是二维。
typedef int Patharc[MAXVEX][MAXVEX]; //用于存储最短路径下标的数组，某个点的前驱
typedef int ShortPathTable[MAXVEX][MAXVEX]; //用于存储到各点到最短路径的权值和

/************************************************/
//构建邻接表
/************************************************/
typedef struct{
    VertexType Vertex[MAXVEX];//顶点表
    EdgeType Arc[MAXVEX][MAXVEX];//邻接矩阵：边表
    int numNodes,numEdges;//附加信息：顶点数和边数
}MGraph;

/************************************************/
//建立无向网图的邻接表结构
/************************************************/
void CreateMGraph(MGraph *G){
    int i, j, k, w;
    //获取输入参数：顶点数和边数
	printf("输入顶点数和边数:");
	scanf("%d,%d",&G->numNodes,&G->numEdges); /* 输入顶点数和边数 */
	printf("\n");
    //获取顶点信息，建立顶点表
    for(i = 0; i <G->numNodes; i++){
		printf("输入顶点值:");
	    scanf("%d",&G->Vertex[i]);
        printf("\n");
    }
    printf("\n");
    //初始化邻接矩阵(边表)，全部的边为INFINITY。
    for(i = 0;i <G->numNodes; i++)
		for(j = 0;j <G->numNodes;j++){
			G->Arc[i][j]=INFINITY;	/* 邻接矩阵初始化 */		    
		}
    //获取边的权值，建立边表信息。
    for(k = 0; k<G->numEdges; k++ ){
		printf("输入边(vi,vj)上的下标i，下标j和权w:");
		scanf("%d,%d,%d", &i, &j, &w); /* 输入边(vi,vj)上的权w */
		printf("\n");
		G->Arc[i][j] = w;
		G->Arc[j][i] = w;//因为是无向图，矩阵是对称的。
    }
}

/************************************************/
//基于迪杰斯特拉算法的最短路径查找程序
//基本算法思想：动态规划
//状态：Patharc* D 和ShortPathTable* P
//初始状态：D(-1)[i][j] = G.Arc[i][j]; P(-1)[i][j] = j
//状态转移方程：
//             D(k)[i][j] = min{D(k-1)[i][j],   D(k-1)[i][k] + D(k-1)[k][j]}
//             IF(D(k)[i][j] = D(k-1)[i][j]),   P(k)[i][j] = P(k-1)[i][j]
//             IF(D(k)[i][j] = D(k-1)[i][k] + D(k-1)[k][j]) P(k)[i][j] = k;
//             
//具体方案：三层循环。
//第一层循环遍历中转点k;
//二层for循环：遍历所有的点i->j,更新D 和 P
/************************************************/
void ShortestPath_Floyd(MGraph *G, Patharc *P, ShortPathTable *D){
    int i,j,k;
    /* 初始化D与P */
    for(i=0; i<G->numNodes; i++)
        for(j=0; j<G->numNodes; j++){
            (*D)[i][j] = G->Arc[i][j];
            (*P)[i][j] = j;
        }
    /* 依据状态方程更新D与P */ 
    for(k=0; k<G->numNodes; k++)
        for(i=0; i<G->numNodes; i++)
            for(j=0; j<G->numNodes; j++){//如果经过下标为k顶点路径比原两点间路径更短
                if((*D)[i][j] > (*D)[i][k] + (*D)[k][j]){
                    (*D)[i][j] = (*D)[i][k] + (*D)[k][j];//将当前两点间权值设为更小的一个 
                    (*P)[i][j] = k;                //路径设置为经过下标为k的顶点
                }
            }
}

/************************************************/
//打印程序
//PathPrint(ShortPathTable* P)
/************************************************/
void PathPrint(int i, int j, ShortPathTable* P){
	int k = (*P)[i][j];
	//这个地方用if判断，不能用while,会在第一次就陷入死循环中。切记！切记！
	//注意控制递归的条件
	if((*P)[i][k] != k){//前部分i->k的终点是k,则终止递归。
		PathPrint(i,  k, P); 
		printf(" --> %d ",k);//注意不要重复打印！
	}
    if(k != j) //k = j,后半部分终点已经是j,则终止递归。
		PathPrint(k,  j, P);   
}
/************************************************/
//test main
/************************************************/
void main(){
	//定义指针以及空间申请。
	//这个地方要注意，吃过很多亏！
    MGraph *G = NULL;
	Patharc *P = NULL;
	ShortPathTable  *D = NULL;
	G = (MGraph*)malloc(sizeof(MGraph));
	P = (Patharc*)malloc(sizeof(Patharc));
	D = (ShortPathTable*)malloc(sizeof(ShortPathTable));

    CreateMGraph(G);
    ShortestPath_Floyd(G, P, D);
    printf("最短路径和权值:\n\n");
    for(int i=0; i<G->numNodes; i++)
        for(int j=i+1; j<G->numNodes; j++){
            printf("%d到%d：%d\n", i,  j, (*D)[i][j]);
			printf("路径为：%d",i);
            PathPrint(i, j, P);
			printf(" --> %d", j);
			printf("\n");
        }
	free(G); free(P); free(D);
	G = NULL; 	P = NULL; 	D = NULL;
}
