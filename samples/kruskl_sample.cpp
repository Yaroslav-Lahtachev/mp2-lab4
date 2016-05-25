#include "Graph.h"
#include "Kruskl.h"
#include <iostream>
#include <fstream>
using namespace std;


void main(int argc, char **argv)
{
	Graph *CurrGraph;
	int ver=atoi(argv[1]);
	int edg=atoi(argv[2]);
	float min=atoi(argv[3]);
	float max=atoi(argv[4]);
	int qnum=atoi(argv[5]);
	//int ver = 6;
	//int edg = 10;
	//int min = 0;
	//int max = 10;
		
	CurrGraph=new Graph(ver, edg);
	CurrGraph->CreateGraph(min, max);
	CurrGraph->pGraphEDG();
	Graph *tree=Kruskl::KrusklAlg(CurrGraph, qnum);
	tree->pTreeEDG();
	
	remove("res.txt");
	ofstream output("res.txt");
	output.setf(output.fixed, output.floatfield);
	output.precision(2);

	output<<ver<<" "<<edg<<endl;
	edg=CurrGraph->getSize();
	Edges* edge;
	for(int j=0; j<edg; j++) 
	{
		edge=CurrGraph->getEdg(j);
		output<<edge->n<<" "<<edge->k<<" "<<edge->w<<endl;
	}
	edg=tree->getSize();
	for(int j=0; j<edg; j++) 
	{
		edge=tree->getEdg(j);
		output<<endl;
		output<<edge->n<<" "<<edge->k<<" "<<edge->w;
	}
	output.close();
	delete CurrGraph;
	delete tree;
}