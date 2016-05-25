#pragma once
#include "tree_lib.h"


class DataHeap : public Data
{
public:	
	DataHeap(int i);
};


class HeapSort
{
public:
	static void heapSort(int *&elems, int n, int d);
};
