#include "Heapsort.h"
#include <ctime>
#include <iostream>
using namespace std;


void main(int argc, char **argv)
{
	time_t  timet;
	time(&timet);
	int Size=atoi(argv[1]);
	int max=atoi(argv[2]);
	int* Elems=new int[Size];
	
	srand((int)timet);
	for(int i=0; i<Size; i++)
		Elems[i]=rand()%max;
	for(int i=0; i<Size; i++)
		cout<<Elems[i]<<" ";
	HeapSort::heapSort(Elems, Size, 4);
	cout<<endl;
	for(int i=0; i<Size; i++)
		cout<<Elems[i]<<" ";
}