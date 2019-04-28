#pragma once

typedef struct
{
	int vertex1;
	int vertex2;
	int weight;
} Edge;



typedef struct
{
	Edge* edges;
	int last;	// ��ǰ���һ��������ڵĽǱ�
} EdgeHeap;


EdgeHeap* createHeap();

void insertEdge(EdgeHeap *heap, Edge edge);

Edge deleteEdge(EdgeHeap* heap);


void testMinHeap();