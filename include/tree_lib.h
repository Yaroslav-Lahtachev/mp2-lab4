#pragma once
#include <algorithm>
#include <iostream>
#define MaxSize 10000
using namespace std;


class Data
{
public:
	float priority;
};


class Tree
{
protected:
	Data **key;
	int d;
	int Size;
public:
	Tree(int d);
	~Tree();

	void input(Data *&i);
	void inputGroup(Data **keys, int num);
	Data* erase();
	Data* erase(int i);

	void transposing(int i, int j);
	void surfacing(int i);
	void immersion(int i);
	void withdrawal(int i);
	void hilling();

	int isFull();
	int isEmpty();
private:
	int minchild(int i);
};