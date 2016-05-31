#include "table.h"

SortTable::SortTable(int Size) : ScanTable(Size){}

TabRecord* SortTable::find(float key)
{
	int M;
	int S = 0;
	int F = count - 1;
	while (S <= F) {
		M = (S + F) / 2;
		if (recs[M]->GetKey() == key) {
			CurrPos = M;
			return recs[M];
		}
		else if (recs[M]->GetKey() > key)
			F = M - 1;
		else
			S = M + 1;
	}
	return 0;
}

int SortTable::add(float key, void* data)
{
	if (isFull())
		return -1;
	int M;
	int S = 0;
	int F = count - 1;
	while (S <= F) {
		M = (S + F) / 2;
		if (recs[M]->GetKey() == key) {
			CurrPos = M;
			break;
		}
		else if (recs[M]->GetKey() > key) {
			F = M - 1;
			CurrPos = M;
		}
		else {
			S = M + 1;
			CurrPos = S;
		}
	}
	for (int i = count; i > CurrPos; i--)
		recs[i] = recs[i - 1];
	recs[CurrPos] = new TabRecord(key, data);
	count++;
	return 0;
}

int SortTable::del(float key)
{
	TabRecord* tmp = pull(key);
	if (!tmp)
		return -1;
	delete tmp;
	return 0;
}

TabRecord* SortTable::pull(float key)
{
	TabRecord* tmp = find(key);
	if (!tmp)
		return 0;
	for (int i = CurrPos; i < count - 1; i++)
		recs[i] = recs[i + 1];
	recs[count - 1] = 0;
	count--;
	return tmp;
}

TabRecord* SortTable::getm()
{
	if (isEmpty())
		return 0;
	return recs[0];
}

TabRecord* SortTable::getM()
{
	if (isEmpty())
		return 0;
	return recs[count - 1];
}