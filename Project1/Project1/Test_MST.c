#include "Graph.h"
#include " MST.h"

int main(void)
{
	Graph* graph = CreatGraph();
	Graph* PrimMST = CreatGraph();
	Graph* Kruskal = CreatGraph();

	Vertex* A = CreateVertex('A');
	Vertex* B = CreateVertex('B');
	Vertex* C = CreateVertex('C');
	Vertex* D = CreateVertex('D');
	Vertex* E = CreateVertex('E');
	Vertex* F = CreateVertex('F');
	Vertex* G = CreateVertex('G');
	Vertex* H = CreateVertex('H');
	Vertex* I = CreateVertex('I');

	AddVertex(graph, A);
	AddVertex(graph, B);
	AddVertex(graph, C);
	AddVertex(graph, D);
	AddVertex(graph, E);
	AddVertex(graph, F);
	AddVertex(graph, G);
	AddVertex(graph, H);
	AddVertex(graph, I);

	AddEdge(A, CreatEdge(A, B, 35));
	AddEdge(A, CreatEdge(A, E, 247));

	AddEdge(B, CreatEdge(A, A, 35));
	AddEdge(B, CreatEdge(A, C, 126));
	AddEdge(B, CreatEdge(A, F, 150));

	AddEdge(C, CreatEdge(A, B, 126));
	AddEdge(C, CreatEdge(A, D, 117));
	AddEdge(C, CreatEdge(A, F, 162));
	AddEdge(C, CreatEdge(A, G, 220));

	AddEdge(D, CreatEdge(D, C, 117));

	AddEdge(E, CreatEdge(E, A, 247));
	AddEdge(E, CreatEdge(E, F, 82));
	AddEdge(E, CreatEdge(E, H, 98));

	AddEdge(F, CreatEdge(F, B, 150));
	AddEdge(F, CreatEdge(F, C, 162));
	AddEdge(F, CreatEdge(F, E, 82));
	AddEdge(F, CreatEdge(F, G, 154));
	AddEdge(F, CreatEdge(F, H, 120));

	AddEdge(G, CreatEdge(G, C, 220));
	AddEdge(G, CreatEdge(G, F, 154));
	AddEdge(G, CreatEdge(G, I, 106));

	AddEdge(H, CreatEdge(H, E, 98));
	AddEdge(H, CreatEdge(H, F, 120));

	AddEdge(I, CreatEdge(I, G, 106));


	printf("Prim's Algorithm\n");
	Prim(graph, B, PrimMST);
	printf(PrimMST);

	Printf("Kruskal's Algoritm\n");
	Kruskal(graph, KruskalMST);
	PrintGraph(KruskalMST);

	DestroyGraph(PrimMST);
	DestroyGraph(KruskalMST);
	DestroyGraph(graph);

	return 0;
}