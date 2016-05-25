#include "DijkstrasAlg.h"

DataFloat::DataFloat(int v, float dist)
{
	this->v = v;
	priority = dist;
}

float* Dijkstra::dijkstra(Graph *&graph, int s)
{
	int n = graph->getVerticesNum();
	if ((s < 0)||(s >= n))
		return 0;
	int m = graph->getRealSize();
	
	Data** dist = new Data*[n];
	int* up = new int[n];

	for (int i = 0; i < n; i++){
		up[i] = 0;
		dist[i] = new DataFloat(i, FLT_MAX);
	}
	dist[s]->priority = 0;

	PriorityQueue *queue = new PriorityQueue(dist, n, 4);

	Edge** edges = graph->getEdgeSet();
	int edgeCount = m;
	while ((edgeCount != 0) && (!queue->isEmpty()))
	{
		Data* tmp = queue->pop();
		int v = ((DataFloat*)tmp)->v;
		int v0 = -1;
		float delta;
		for (int i = 0; i < m; i++)
		{
			v0 = -1;
			if (edges[i]->K == v)
				v0 = edges[i]->N;
			if (edges[i]->N == v)
				v0 = edges[i]->K;
			if (v0 == -1) continue;
			//edgeCount--;
			delta = dist[v0]->priorities - (dist[v]->priorities + graph->getWeight(v, v0));
			if (delta > 0){
				dist[v0]->priorities = graph->getWeight(v, v0) + dist[v]->priorities;
				up[v0] = v;
			}
		}
	}
	
	float *result = new float[n];
	for (int i = 0; i < n; i++)
		result[i] = dist[i]->priorities;

	for (int i = 0; i < n; i++)
		delete dist[i];
	delete []dist;
	delete queue;
	delete []up;

	return result;
}