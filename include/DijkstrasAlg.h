#pragma once
#include "Graph.h"
#include "tree_lib.h"
#include "queue.h"
#include <cfloat>

class DataFloat : public Data 
{
public:
	DataFloat(int v, float dist);
	int v;
};

class Dijkstra {
public:
	static float* dijkstra(Graph *&graph, int s); 
};