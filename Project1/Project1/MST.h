#pragma once
#ifndef MST_H
#define MST_H

#include "Graph.h"
#include "PriorityQueue.h"
#include "DisjoinSet.h"

#define MAX_WEIGHT 36267

void prim(Graph* G, Vertex* StartVertex, Graph* MST);
void kruskal(Graph* G, Graph* MST);

#endif