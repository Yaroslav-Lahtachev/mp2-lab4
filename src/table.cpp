#include "table.h"

TabRecord::TabRecord(float key, void * data)
{
	this->key = key;
	this->data = data;
}

float TabRecord::GetKey() const
{
	return this->key;
}

void* TabRecord::GetData() const
{
	return this->data;
}

Table::Table(int Size)
{
	if (Size < 0 || Size > max_size)
		throw ("wrong size");
	this->Size = Size;
	this->count = 0;
	this->CurrPos = 0;
}

int Table::isEmpty() const
{
	return count == 0;
}

int Table::isFull() const
{
	return count >= Size;
}

int Table::getDataCount() const
{
	return count;
}

int Table::Reset()
{
	CurrPos = 0;
	return isTableEnded();
}

int Table::GetNext()
{
	if (!isTableEnded())
		CurrPos++;
	return isTableEnded();
}

int Table::isTableEnded()
{
	return count >= Size;
}


