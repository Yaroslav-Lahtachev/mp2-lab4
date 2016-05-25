#pragma once
#include "Graph.h"
#include "tree_lib.h"
#include "queue.h"
#include <cfloat>

const int INF=10000000;


class DijkstraData:public Data
{
public:
	int num;
	DijkstraData(int num, float d);
};


class Dijkstra
{
public:
	static void DijkstraAlg(Graph *&CurrGraph, int startV); 
};