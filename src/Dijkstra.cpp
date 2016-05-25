#include "Dijkstra.h"


DijkstraData::DijkstraData(int num, float d)
{
	this->num=num;
	priority=d;
}


void Dijkstra::DijkstraAlg(Graph *&CurrGraph, int startV)
{
	int ver=CurrGraph->getVer();
	if (!ver)
		throw "no ver";
	if (startV<0 || startV>ver)
		throw "wrong start ver";
	int edg=CurrGraph->getSize();
	Data** dist=new Data*[ver];
	int* p=new int[ver];
	for (int i=0; i<ver; i++)
	{
		p[i]=0;
		dist[i]=new DijkstraData(i, INF);
	}
	dist[startV]->priority=0;
	Queue* q=new QueueHeap(dist, ver, 4);
	Edges** edges=CurrGraph->getEdgArr();
	while (!q->isEmpty())
	{
		int currV=((DijkstraData*)q->popidx(0))->num;
		float d;
		for (int i=0; i<edg; i++)
		{
			if (currV==edges[i]->n)
			{
				d=dist[edges[i]->k]->priority;
				if (d>dist[edges[i]->n]->priority + CurrGraph->getW(edges[i]->n, edges[i]->k))
				{
					dist[edges[i]->k]->priority=dist[edges[i]->n]->priority + CurrGraph->getW(edges[i]->n, edges[i]->k);
					p[edges[i]->k]=edges[i]->n;
					q->update();
				}
			}
			if (currV==edges[i]->k)
			{
				d=dist[edges[i]->n]->priority;
				if (d>dist[edges[i]->k]->priority + CurrGraph->getW(edges[i]->n, edges[i]->k))
				{
					dist[edges[i]->n]->priority=dist[edges[i]->k]->priority + CurrGraph->getW(edges[i]->n, edges[i]->k);
					p[edges[i]->n]=edges[i]->k;
					q->update();
				}
			}
		}
	}
	for (int k = 0; k < ver; k++)
		cout << p[k];
	cout << endl;
	cout << endl;
	
	for (int i=0; i<ver; i++)
	{
		if (i == startV) {
			cout <<startV<<endl ;
			continue;
		}
		cout<<p[i]<<"-"<<i<<"   "<<dist[i]->priority<<endl;
		delete dist[i];
	}
	delete[]dist;
	delete q;
}