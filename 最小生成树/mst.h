#pragma once
#define EDGENUM 10
#define VERTEXNUM 5
#include "heap.h"



/*最小生成树*/
typedef struct			
{
	Edge* edges;
	int size;
} MST;	

int visted[6];	// 结点数组


/*判断是否遍历结束*/
int isFinished();

MST* Kruskal(EdgeHeap *heap);

/*判断某条边是否已经在生成树的集合当中仅用于Kruskal算法中*/
int EdgeInMST(Edge edge);	

void testKruskal();

void printMST(MST* mst);


void Prims();
