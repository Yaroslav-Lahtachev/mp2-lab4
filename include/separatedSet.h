#pragma once


class separatedSet
{
private:
	int *arr;
	int Size;
public:
	separatedSet(int Size);
	~separatedSet();

	void singelton(int i);
	void unionS(int i, int j);
	int subDef(int i);
	int getSize(int i);
};