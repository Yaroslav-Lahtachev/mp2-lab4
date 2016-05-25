#include "queue.h"


QueueHeap::QueueHeap(int d)
{
	heap = new Tree(d);
}
QueueHeap::QueueHeap(Data **keys, int num, int d)
{
	heap = new Tree(d);
	heap->inputGroup(keys, num);
}
QueueHeap::~QueueHeap()
{
	delete heap;
}

void QueueHeap::add(Data *&key)
{
	heap->input(key);
}
Data* QueueHeap::popidx(int i)
{
	return heap->erase(i);
}
/*Data* QueueHeap::popMin()
{
	return heap->erase();
}*/
void QueueHeap::update()
{
	heap->hilling();
}

int QueueHeap::isFull()
{
	return heap->isFull(); 
}
int QueueHeap::isEmpty()
{
	return heap->isEmpty(); 
}