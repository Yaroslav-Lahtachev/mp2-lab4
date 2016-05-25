#include "Kruskl.h"


KrasklEdges::KrasklEdges(Edges *edge)
{
	this->edge=edge;
	priority=edge->w;
}


Graph* Kruskl::KrusklAlg(Graph *&CurrGraph, int qnum)
{
	int n, k, A, B;
	float w;
	int ver=CurrGraph->getVer();
	if(!ver)
		throw "no ver";
	int edg=CurrGraph->getSize();
	Graph *tree=new Graph(ver);
	separatedSet *SArr=new separatedSet(ver);
	for(int i=0; i<ver; i++)
		SArr->singelton(i);
	
	
		
	Queue *q = QueueFactory::createQueue(static_cast<Qnum>(qnum));
	Data **edges = new Data*[edg];
	for (int i = 0; i < edg; i++) {
		edges[i] = new KrasklEdges(CurrGraph->getEdgArr()[i]);
		q->add(edges[i]);
	}

	int Size=0;
	while(Size<ver-1 && !q->isEmpty())
	{
		Data* e=q->popidx(0);
		n=((KrasklEdges*)e)->edge->n;
		k=((KrasklEdges*)e)->edge->k;
		w=((KrasklEdges*)e)->edge->w;
		A=SArr->subDef(n);
		B=SArr->subDef(k);
		if(A!=B)
		{
			SArr->unionS(A, B);
			tree->inputEdge(n, k, w);
			Size++;
		}
	}
	delete []edges;
	delete SArr;
	delete q;
	return tree;	
}