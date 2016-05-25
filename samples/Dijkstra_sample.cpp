#include "Graph.h"
#include "Dijkstra.h"
using namespace std;


void main(int argc, char **argv)
{
	/*Graph *CurrGraph = new Graph(5, 7);
	CurrGraph->inputEdge(0, 1, 0.1);
	CurrGraph->inputEdge(0, 3, 8);
	CurrGraph->inputEdge(1, 2, 9);
	CurrGraph->inputEdge(1, 4, 7);
	CurrGraph->inputEdge(0, 4, 0.2);
	CurrGraph->inputEdge(4, 3, 0.3);
	CurrGraph->inputEdge(3, 2, 0.4);
	CurrGraph->pGraphEDG();
	Dijkstra::DijkstraAlg(CurrGraph, 0);*/ 

	Graph *CurrGraph;
	int	ver=atoi(argv[1]);
	int	edg=atoi(argv[2]);
	int	startV=atoi(argv[3]);
	int min=atoi(argv[4]);
	int max=atoi(argv[5]);

	CurrGraph = new Graph(ver, edg);
	CurrGraph->CreateGraph(min, max);
	CurrGraph->pGraphEDG();

	Dijkstra::DijkstraAlg(CurrGraph, startV);

	/*Graph *CurrGraph = new Graph(6, 10);
	CurrGraph->inputEdge(0, 1, 7.63787);
	CurrGraph->inputEdge(0, 2, 0.913114);
	CurrGraph->inputEdge(0, 3, 4.62477);
	CurrGraph->inputEdge(1, 2, 0.55269);
	CurrGraph->inputEdge(1, 3, 7.63787);
	CurrGraph->inputEdge(1, 4, 9.43693);
	CurrGraph->inputEdge(2, 4, 7.75445);
	CurrGraph->inputEdge(3, 4, 5.13138);
	CurrGraph->inputEdge(5, 2, 9.65178);
	CurrGraph->inputEdge(5, 4, 5.51347);
	CurrGraph->pGraphEDG();
	Dijkstra::DijkstraAlg(CurrGraph, 0);*/
}