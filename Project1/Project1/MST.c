#include "MST.h"

void Prim(Graph* G, Vertex* StartVertex, Graph* MST)
{



}

void Kruskal(Graph* G, Graph* MST)
{
	int i;
	Vertex* CurrentVertex = NULL;
	Vertex** MSTVerices = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);
	DisjoinSet** VertexSet = (DisjoinSet**)malloc(sizeof(DisjoinSet*) * G->VertexCount);

	PriorityQueue* PQ = PQ_Create(10);

	i = 0;
	CurrentVertex = G->Vertices;
	while ( CurrntVertex)
}