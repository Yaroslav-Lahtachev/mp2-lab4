#include "Graph.h"


Edges::Edges(int n, int k, float w)
{
	this->n=n;
	this->k=k;
	this->w=w;
}
Graph::Graph(int ver)
{
	if (ver<0||ver>maxVer)
		throw "wrong vertices num";
	this->ver=ver;
	this->edg=ver*(ver-1)/2;
	Size=0;
	verArr=new int[ver];
	edgArr=new Edges*[edg];
}
Graph::Graph(int ver, int edg)
{
	if (ver<0||ver>maxVer)
		throw "wrong vertices num";
	if (edg<0||edg>ver*(ver-1)/2)
		throw "wrong edges num";
	this->ver=ver;
	this->edg=edg;
	Size=0;
	verArr=new int[ver];
	edgArr=new Edges*[edg];
}
Graph::~Graph()
{
	for (int i=0; i<Size; i++)
		delete edgArr[i];
	delete[]edgArr;
	delete[]verArr;
}

void Graph::CreateVer(int &n, int &k)
{
	n = rand()%ver;
	k = rand()%ver;
	if(n==k || search(n, k)!=-1) 
		CreateVer(n, k);
}
void Graph::CreateGraph(float minW, float maxW)
{
	if (minW > maxW)
		throw("wrong weight");
	int n;
	int k;
	float w;
	time_t  timet;
	time(&timet);
	srand((int)timet);
	for(int i=0; i<edg; i++)
	{
		CreateVer(n, k);
		w = rand()*(float)(maxW - minW) / RAND_MAX + minW;
		edgArr[i]=new Edges(n, k, w);
		Size++;
	}
	
}

void Graph::inputEdge(int n, int k, float w)
{
	if(isFull())
		throw "Graph overflow";
	if(search(n,k)!=-1)
		throw "edge already have";
	if (n==k)
		throw "wrong n&k";
	edgArr[Size]=new Edges(n, k, w);
	Size++;
}
void Graph::deleteEdge(int n, int k)
{
	int i=search(n, k);
	if (i==-1)
		throw("nonavailable edg");
	delete edgArr[i];
	edgArr[i]=edgArr[Size-1];
	Size--;
}
int Graph::search(int n, int k)
{
	for(int i=0; i<Size; i++)
	{
		if((edgArr[i]->n==n && edgArr[i]->k==k)||(edgArr[i]->n==k && edgArr[i]->k==n))
			return i;
	}
	return -1;
}

int Graph::getVer()
{
	return ver;
}
int Graph::getEdgNum()
{
	return edg;
}
int Graph::getSize()
{
	return Size;
}
float Graph::getW(int n, int k)
{
	int i=search(n, k);
	return edgArr[i]->w;
}
Edges* Graph::getEdg(int i)
{
	return edgArr[i];
}
Edges** Graph::getEdgArr()
{
	if (Size == 0)
		return 0;
	return edgArr;
}

int Graph::isFull()
{
	return edg==Size;
}
int Graph::isEmpty()
{
	return Size==0;
}

void Graph::pGraphEDG()
{
	for (int i=0; i<edg; i++)
			cout<<edgArr[i]->n<<"-"<<edgArr[i]->k<<'('<<edgArr[i]->w<<')'<<"; "<<endl;
	cout<<endl;
}
void Graph::pTreeEDG()
{
	for (int i=0; i<ver-1; i++)
			cout<<edgArr[i]->n<<"-"<<edgArr[i]->k<<'('<<edgArr[i]->w<<')'<<"; "<<endl;
	cout<<endl;
}