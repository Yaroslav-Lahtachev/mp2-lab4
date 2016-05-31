#include "queue.h"

QueueTab::QueueTab()
{
	tab = new SortTable(max_size);
}

QueueTab::QueueTab(int size)
{
	tab = new SortTable(size);
}

QueueTab::~QueueTab()
{
	delete tab;
}

void QueueTab::add(Data *&key)
{
	if (tab->add(key->priority, key))
		throw "table overflow";
}

Data* QueueTab::popidx(int i = 0)
{
	TabRecord* m = tab->getm();
	TabRecord* tmp = tab->pull(m->GetKey());
	return (Data*)tmp->GetData();
}

int QueueTab::isFull()
{
	return tab->isFull();
}

int QueueTab::isEmpty()
{
	return tab->isEmpty();
}