#include "Graph.h"
#include "Kruskl.h"
#include <iostream>
#include <fstream>
using namespace std;


int main(int argc, char **argv)
{
	Graph *CurrGraph;  //рандомный граф
	int ver, edg, qnum;
	if (argc == 6) {
		try {
			ver = atoi(argv[1]);
			edg = atoi(argv[2]);
			float min = atoi(argv[3]);
			float max = atoi(argv[4]);
			qnum = atoi(argv[5]);
			CurrGraph = new Graph(ver, edg);
			CurrGraph->CreateGraph(min, max);
		}
		catch (...) {
			return -1;
		}
	}
	else if (argc==2) {
		string file(argv[1]);
		ifstream input(file);
		if (!input)
			cout << "smth went wrong";
		try {
			input >> ver;
			input >> edg;
			input >> qnum;
			CurrGraph = new Graph(ver,edg);
			int n, k;
			float w;
			while (!input.eof()) {
				input >> n;
				input >> k;
				input >> w;
				CurrGraph->inputEdge(n, k, w);
			}
		}
		catch (...) {
			return -1;
		}
	input.close();
	}
	CurrGraph->pGraphEDG();
	
	
	//int ver = 6;
	//int edg = 10;
	//int min = 0;
	//int max = 10;
		
	//CurrGraph=new Graph(ver, edg);
	//CurrGraph->CreateGraph(min, max);
	//
	//int edg = 6;  //граф-бабочка
	//int ver = 5;

	/*Graph *CurrGraph = new Graph(5, 6);
	CurrGraph->inputEdge(0, 1, 0.5);
	CurrGraph->inputEdge(0, 2, 1);
	CurrGraph->inputEdge(1, 2, 2);
	CurrGraph->inputEdge(2, 4, 3);
	CurrGraph->inputEdge(2, 3, 1);
	CurrGraph->inputEdge(4, 3, 0.5);
	int qnum = 2;
	CurrGraph->pGraphEDG();*/

	//int edg = 3;  // граф-треугольный
	//int ver = 3;

	//Graph *CurrGraph = new Graph(3, 3);
	//CurrGraph->inputEdge(0, 1, 1);
	//CurrGraph->inputEdge(0, 2, 3);
	//CurrGraph->inputEdge(1, 2, 2);
	//int qnum = 2;
	//CurrGraph->pGraphEDG();

	//int edg = 6;  // дерево
	//int ver = 7;

	//Graph *CurrGraph = new Graph(7, 6);
	//CurrGraph->inputEdge(2, 1, 1);
	//CurrGraph->inputEdge(0, 2, 0.5);
	//CurrGraph->inputEdge(3, 2, 1);
	//CurrGraph->inputEdge(2, 4, 3);
	//CurrGraph->inputEdge(2, 5, 2);
	//CurrGraph->inputEdge(5, 6, 1);
	//int qnum = 2;
	//CurrGraph->pGraphEDG();

	//int edg = 8;  // мега-граф
	//int ver = 13;

	//Graph *CurrGraph = new Graph(8, 13);
	//CurrGraph->inputEdge(0, 1, 2);
	//CurrGraph->inputEdge(0, 2, 4);
	//CurrGraph->inputEdge(0, 7, 3);
	//CurrGraph->inputEdge(0, 6, 3);
	//CurrGraph->inputEdge(1, 7, 1);
	//CurrGraph->inputEdge(2, 3, 4);
	//CurrGraph->inputEdge(2, 6, 0.5);
	//CurrGraph->inputEdge(3, 4, 0.5);
	//CurrGraph->inputEdge(3, 1, 8);
	//CurrGraph->inputEdge(4, 5, 7);
	//CurrGraph->inputEdge(4, 6, 2);
	//CurrGraph->inputEdge(5, 6, 1);
	//CurrGraph->inputEdge(6, 7, 2);

	//int qnum = 2;
	//CurrGraph->pGraphEDG();
	
	Graph *tree=Kruskl::KrusklAlg(CurrGraph, qnum);
	tree->pTreeEDG();
	
	remove("tree.txt");
	ofstream output("tree.txt");
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