#include "queue.h"

QueueTree::QueueTree()
{
	tree = new AVLTree();
}

QueueTree::QueueTree(Data **keys, int num)
{
	tree = new AVLTree();
	for (int i = 0; i < num; i++)
	{
		AVLNode *node = new AVLNode;
		node->key = keys[i]->priority;
		node->data = keys[i];
		tree->add(node);
	}
}

QueueTree::~QueueTree()
{
	delete tree;
}

void QueueTree::add(Data *&key)
{
	AVLNode *node = new AVLNode;
	node->key = key->priority;
	node->data = key;
	tree->add(node);
}

Data* QueueTree::popidx(int i=0)
{
	Node *tmp = tree->searchMin();
	Node * tmp1 = tree->pull(tmp);
	return (Data*)tmp1->data;
}

int QueueTree::isFull()
{
	AVLNode *tmp;
	try {
		tmp = new AVLNode;
	}
	catch (...) {
		return 1;
	}
	delete tmp;
	return 0;
}

int QueueTree::isEmpty()
{
	return tree->isEmpty();
}

