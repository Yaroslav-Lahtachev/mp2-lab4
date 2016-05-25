#pragma once
#include <iostream>
#include <ctime>
#define maxVer 1000
using namespace std;


class Edges
{
public: 
	int n;
	int k;
	float w;
	Edges(int n, int k, float w);
};


class Graph 
{
private:
	int ver;
	int edg;
	int Size;
	int range;
	Edges** edgArr;
	int* verArr;

public:
	Graph(int ver);
	Graph(int ver, int edg);
	~Graph();

	void CreateVer(int &n, int &k);
	void CreateGraph(float minW, float maxW);

	void inputEdge(int n, int k, float w);
	void deleteEdge(int n, int k);
	int search(int n, int k);

	int getVer();
	int getEdgNum();
	int getSize();
	float getW(int n, int k);
	Edges* getEdg(int i);
	Edges** getEdgArr();

	int isFull();
	int isEmpty();

	void pGraphEDG();
	void pTreeEDG();
};