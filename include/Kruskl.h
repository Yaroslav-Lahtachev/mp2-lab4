#pragma once
#include "Graph.h"
#include "tree_lib.h"
#include "queue.h"
#include "separatedSet.h"


class KrasklEdges : public Data
{
public:
	Edges *edge;
	KrasklEdges(Edges *edge);
};


class Kruskl
{
public:
	static Graph* KrusklAlg(Graph *&CurrGraph, int qnum);
};