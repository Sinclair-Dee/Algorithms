//********************************************************************************//
//问题：
//无向图G有N个结点(1<N<=1000)及一些边，每一条边上带有正的权重值。 
//找到结点1到结点N的最短路径，或者输出不存在这样的路径。
//note：在每一步中，对于那些没有计算过的结点， 及那些已经计算出从结点1到它的最短路径的结点，
//如果它们间有边， 则计算从结点1到未计算结点的最短路径。
//狄新凯
//2017/8/13
//Status:Compiled!!!
//********************************************************************************//
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

typedef int Patharc[MAXVEX]; //用于存储最短路径下标的数组，某个点的前驱
typedef int ShortPathTable[MAXVEX]; //用于存储到各点到最短路径的权值和

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
//算法思想：体现了贪心策略的思想
//分解思路:
//      到达某节点的cost最小路径  -->（从这里面筛选）--> { 到达其相邻节点的最小路径 }
//      独一选择性:
//          只挑选： Min {到达其相邻节点的最短路径}
//具体方案：
//两层循环，第一层循环遍历所有顶点;
//第二层两个for循环：一个寻找最短路径的点k(最佳状态)，另一个循环通过该点更新最短路径，达到该状态下的最优解，体现出了贪心策略
/************************************************/
int ShortestPath_Dijkstra(MGraph *G, VertexType ver0, VertexType verN,Patharc *P, ShortPathTable *D){
    int v,w,k,min;
	int v0, vn;//获取起始点和终点的下标
	for(int i=0; i<G->numNodes; i++){
		if(G->Vertex[i] ==ver0) v0 = i;
		if(G->Vertex[i] == verN) vn = i;
	}
    //标记数组final[],标记已经求得vo->vw的最短路径
    int final[MAXVEX];
    //初始化数据
	for(v=0; v<G->numNodes; v++){
		final[v] = 0;//全部顶点未打标记
		(*D)[v] = G->Arc[v0][v];//初始化v0点到其他点的权值(*D)[v]
        (*P)[v] = 0;//初始化所有点的前驱都是v0			
	}  
        
    //初始状态：(*D)[v0] = 0;final[v0] = 1;(*P)[v0] = v0;
	(*D)[v0] = 0;
	final[v0] = 1;
	(*P)[v0] = v0;
    //For v = 1 to G.numNodes
	for(v=1; v<G->numNodes; v++){
		int min = INFINITY;//初始化当前点离v0的距离，默认是最大
		//For w =0 to G.numVertexes
		for(w=0;w<G->numNodes;w++){
		    //迭代，筛选到达v0最小路径的点 k
			if(!final[w] && (*D)[w]<min){
				k = w;
				min = (*D)[w];
			}
		}
		//更新final[k]
		final[k] = 1;
		//For w =0 to G.numVertexes
		for(w=0;w<G->numNodes;w++){
			//IF(经过k顶点的路径比现在的的路径短)
			if(!final[w] && min+G->Arc[k][w]< (*D)[w]){
				    (*D)[w] = min+G->Arc[k][w];//更新v0通过K点而到达其他相邻结点的最小路径*D[w]
					(*P)[w] = k; //更新满足条件的点w的前驱*P
			}
		}
	if(v == vn) break;
	}
    return (*D)[vn];
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
    int ShortestPat = ShortestPath_Dijkstra(G, 0, 3,P, D);
    if(ShortestPat == INFINITY)
        	printf("无最短路径");
    printf("最短路径为:%d",ShortestPat);
	free(G); free(P); free(D);
	G = NULL; 	P = NULL; 	D = NULL;
}