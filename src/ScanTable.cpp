#include "table.h"

float ScanTable::GetKey() const
{
	return recs[CurrPos]->GetKey();
}

void* ScanTable::GetData() const
{
	return recs[CurrPos]->GetData();
}

ScanTable::ScanTable(int Size) : Table(Size)
{
	if (Size < 0 || Size > max_size)
		throw ("wrong size");
	recs = new TabRecord*[Size];
	for (int i = 0; i < Size; i++)
		recs[i] = 0;
}

ScanTable::~ScanTable()
{
	for (int i = 0; i < count; i++)
		delete recs[i];
	delete[]recs;
}

TabRecord* ScanTable::find(float key)
{
	for (int i = 0; i < count; i++)
		if (recs[i]->GetKey() == key) {
			CurrPos = i;
			return recs[i];
		}
	return 0;
}

int ScanTable::add(float key, void* data)
{
	if (isFull())
		return -1;
	count++;
	recs[count] = new TabRecord(key, data);
	return 0;
}

int ScanTable::del(float key)
{
	TabRecord* tmp = pull(key);
	if (!tmp)
		return -1;
	delete tmp;
	return 0;
}

TabRecord* ScanTable::pull(float key)
{
	if (!find(key))
		return 0;
	TabRecord* tmp = recs[CurrPos];
	recs[CurrPos] = recs[count - 1];
	count--;
	return tmp;
}

TabRecord* ScanTable::getm()
{
	if (isEmpty())
		return 0;
	TabRecord* min = recs[0];
	for (int i = 0; i < count; i++)
		if (recs[i]->GetKey() < min->GetKey())
			min = recs[i];
	return min;
}

TabRecord* ScanTable::getM()
{
	if (isEmpty())
		return 0;
	TabRecord* max = recs[0];
	for (int i = 0; i < count; i++)
		if (recs[i]->GetKey() > max->GetKey())
			max = recs[i];
	return max;
}

