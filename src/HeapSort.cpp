#include "Heapsort.h"


DataHeap::DataHeap(int i)
{
	this->priority=i;
}


void HeapSort::heapSort(int *&Elems, int Size, int d)
{ 
	if(!Elems) 
		throw "bad arr";
	if (Size<=0)
		throw "wrong size";
	if (d<=0)
		throw "wrong d";
	Data** elems=new Data*[Size];
	for(int i=0; i<Size; i++)
		elems[i]=new DataHeap(Elems[i]);
	Tree* heap=new Tree(d);
	heap->inputGroup(elems, Size);
	for(int i=Size-1; i>0; --i)
	{
		heap->transposing(i, 0);
		Elems[i] =(int)heap->erase()->priority;
		heap->immersion(0);	
	}
	Elems[0] =(int)heap->erase()->priority;
	delete heap;
	for(int i = 0; i < Size; i++)
		delete elems[i];
	delete []elems;
}