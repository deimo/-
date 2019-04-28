#pragma once
#define EDGENUM 10
#define VERTEXNUM 5
#include "heap.h"



/*��С������*/
typedef struct			
{
	Edge* edges;
	int size;
} MST;	

int visted[6];	// �������


/*�ж��Ƿ��������*/
int isFinished();

MST* Kruskal(EdgeHeap *heap);

/*�ж�ĳ�����Ƿ��Ѿ����������ļ��ϵ��н�����Kruskal�㷨��*/
int EdgeInMST(Edge edge);	

void testKruskal();

void printMST(MST* mst);


void Prims();
