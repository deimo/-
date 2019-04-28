#include "mst.h"
#include <stdio.h>
#include <stdlib.h>

int isFinished()
{
	for (int i = 1; i < 6; i++)
	{
		if (visted[i] == 0)
			return 0;
	}
	return 1;
}


/*Kruskal最小生成树算法*/
MST* Kruskal(EdgeHeap* heap)
{
	for (int i = 0; i < VERTEXNUM + 1; i++)		// 初始化访问的结点
	{
		visted[i] = 0;
	}
	MST* mst = (MST*)malloc(sizeof(MST));
	mst->size = 0;
	mst->edges = (Edge*)malloc(sizeof(Edge) * (VERTEXNUM - 1) );		// n个顶点一共有n-1条边

	
	while (!isFinished())			 // 不考虑图不连通的情形
	{
		Edge minEdge = deleteEdge(heap);
		if (!EdgeInMST(minEdge))	 // 这条边不在最小生成树当中
		{
			mst->edges[mst->size].vertex1 = minEdge.vertex1;
			mst->edges[mst->size].vertex2 = minEdge.vertex2;
			mst->edges[mst->size].weight = minEdge.weight;
			mst->size++;
			visted[minEdge.vertex1] = 1;
			visted[minEdge.vertex2] = 1;
		}
	}
	return mst;
}

int EdgeInMST(Edge edge)
{
	int vertex1 = edge.vertex1;
	int vertex2 = edge.vertex2;
	if (visted[vertex1] == 0 || visted[vertex2] == 0)	// 只有有一个顶点未被访问，就认为是不在最小生成树当中的
	{
		return 0;
	}
	return 1;
}


void printMST(MST* mst)
{
	for (int i = 0; i < mst->size ; i++)
	{
		printf("==>[%d, %d](%d)", mst->edges[i].vertex1, mst->edges[i].vertex2, mst->edges[i].weight);
	}
	printf("\n");
}


void testKruskal()
{
	EdgeHeap* heap = createHeap();
	MST *mst = Kruskal(heap);
	printMST(mst);
}

