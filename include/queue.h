#pragma once
#include "tree_lib.h"
#include "AVL.h"
#include "table.h"

enum Qnum {
	HEAP = 1,
	AVL = 2,
	Tab = 3
};


class Queue
{
public:
	Queue() {};
	virtual void add(Data *&key) = 0;
	virtual Data* popidx(int i) = 0;
	//virtual Data* popMin() = 0;
	virtual void update() = 0;
	virtual int isFull() = 0;
	virtual int isEmpty() = 0;
}; 

class QueueHeap : public Queue {
protected:
	Tree *heap;
public:
	QueueHeap(int d=4);
	QueueHeap(Data **keys, int num, int d);
	~QueueHeap();

	virtual void add(Data *&key);
	virtual Data* popidx(int i);
	//virtual Data* popMin();
	virtual void update();

	virtual int isFull();
	virtual int isEmpty();
};

class QueueTree : public Queue {
protected:
	AVLTree *tree;
public:
	QueueTree();
	QueueTree(Data **keys, int num);
	~QueueTree();

	virtual void add(Data *&key);
	virtual Data* popidx(int i);
	virtual void update() {};

	virtual int isFull();
	virtual int isEmpty();
};

class QueueTab : public Queue {
protected:
	SortTable* tab;
public:
	QueueTab();
	QueueTab(int Size);
	~QueueTab();

	virtual void add(Data *&key);
	virtual Data* popidx(int i);
	virtual void update() {};

	virtual int isFull();
	virtual int isEmpty();
};

class QueueFactory {
public:
	static Queue* createQueue(Qnum qid)
	{
		Queue *q;
		switch (qid)
		{
		case 1: q = new QueueHeap(); break;
		case 2: q = new QueueTree(); break;
		case 3: q = new QueueTab(); break;
		}
		return q;
	}
};