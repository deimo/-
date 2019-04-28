#include "mst.h"
#include <stdlib.h>
#include <stdio.h>

void insertEdge(EdgeHeap* heap, Edge edge)
{
	
	int position = heap->last + 1;
	for (; heap->edges[position / 2].weight > edge.weight; position /= 2)
	{
		heap->edges[position].weight = heap->edges[position / 2].weight;
		heap->edges[position].vertex1 = heap->edges[position / 2].vertex1;
		heap->edges[position].vertex2 = heap->edges[position / 2].vertex2;
	}
	heap->edges[position].vertex1 = edge.vertex1;
	heap->edges[position].vertex2 = edge.vertex2;
	heap->edges[position].weight = edge.weight;
	heap->last++;
}

Edge deleteEdge(EdgeHeap* heap)
{
	Edge edge = heap->edges[1];
	int last = heap->last;
	Edge tempEdge = heap->edges[heap->last];

	heap->last--;
	int parent, child;
	for ( parent = 1; parent * 2 <= heap->last; parent=child)
	{
		child = 2 * parent;
		if (child != heap->last && heap->edges[child].weight > heap->edges[child + 1].weight )	// 取左右孩子中较小的值去比较
		{
			child++;
		}
		if (tempEdge.weight > heap->edges[child].weight)
		{
			heap->edges[parent].weight = heap->edges[child].weight;
			heap->edges[parent].vertex1 = heap->edges[child].vertex1;
			heap->edges[parent].vertex2 = heap->edges[child].vertex2;
		}
		else
		{
			break;
		}
	}
	heap->edges[parent].weight = tempEdge.weight;
	heap->edges[parent].vertex1 = tempEdge.vertex1;
	heap->edges[parent].vertex2 = tempEdge.vertex2;
	
	return edge;
}


EdgeHeap* createHeap()
{
	int edgesData[10][3] = {
		{1, 2, 7}, {1, 3, 6}, {1, 4, 5}, {1, 5, 12}, {2, 3, 14},
		{2, 4, 8}, {2, 5, 8}, {3, 4, 4}, {3, 5, 9}, {4, 5, 2}
	};
	EdgeHeap* heap = (EdgeHeap*)malloc(sizeof(EdgeHeap));
	heap->edges = (Edge*)malloc((EDGENUM + 1) * sizeof(Edge));

	heap->last = 0;		// 结点所在的最后一个位置
	for (int i = 0; i <= 10; i++)
	{
		heap->edges[i].vertex1 = 0;
		heap->edges[i].vertex2 = 0;
		heap->edges[i].weight = 0;
	}

	for (int i = 0; i < 10; i++)
	{
		Edge edge = { edgesData[i][0], edgesData[i][1], edgesData[i][2] };
		insertEdge(heap, edge);
	}

	return heap;
}


void testMinHeap()
{
	EdgeHeap* heap = createHeap();
	printf("初始化后堆中的序列：\n");
	for (int i = 1; i < EDGENUM + 1; i++)
	{
		printf("[%d, %d](%d)\t", heap->edges[i].vertex1, heap->edges[i].vertex2, heap->edges[i].weight);
		if (i % 5 == 0)
		{
			printf("\n");
		}
	}	
	printf("每次获取堆中的最小元素：\n");
	for (int i = 1; i < EDGENUM + 1; i++)
	{
		Edge minEdge = deleteEdge(heap);
		printf("[%d, %d](%d)\t", minEdge.vertex1,minEdge.vertex2, minEdge.weight);
		if (i % 5 == 0)
		{
			printf("\n");
		}
	}

}

