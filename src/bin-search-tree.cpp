#include "bin-search-tree.h"

BinSearchTree::BinSearchTree()
{
	root = 0;
}

BinSearchTree::~BinSearchTree()
{
	DelNode(root);
}

void BinSearchTree::DelNode(Node *node)
{
	if (!node)
		return;
	DelNode(node->pleft);
	DelNode(node->pright);
	delete node;
}

Node* BinSearchTree::searchMin(Node *node)
{
	Node *tmp;
	if (!node)
		tmp = root;
	else
		tmp = node;
	if (!tmp)
		return 0;
	while (tmp->pleft)
		tmp = tmp->pleft;
	return tmp;
}

Node* BinSearchTree::searchMax(Node *node)
{
	Node *tmp;
	if (!node)
		tmp = root;
	else
		tmp = node;
	if (!tmp)
		return 0;
	while (tmp->pright)
		tmp = tmp->pright;
	return tmp;
}

Node* BinSearchTree::searchPrev(Node *node)
{
	if (!node)
		return 0;
	if (node->pleft)
		return searchMax(node->pleft);

	Node *tmp = node;
	while ((tmp->parent) && (tmp == tmp->parent->pleft))
		tmp = tmp->parent;
	return tmp;
}

Node* BinSearchTree::searchNext(Node *node)
{
	if (!node)
		return 0;
	if (node->pright)
		return searchMin(node->pright);

	Node *tmp = node;
	while ((tmp->parent) && (tmp == tmp->parent->pright))
		tmp = tmp->parent;
	return tmp;
}

Node* BinSearchTree::search(float key)
{
	Node *tmp = root;
	if (!tmp)
		return 0;
	while ((tmp) && (tmp->key != key))
	{
		if (key < tmp->key)
			tmp = tmp->pleft;
		else
			tmp = tmp->pright;
	}
	return tmp;
}

void BinSearchTree::add(Node *&node)
{
	if (!root)
	{
		root = node;
		return;
	}
	Node *tmp = root;
	Node *tmpPrev;
	while (tmp) {
		tmpPrev = tmp;
		if (tmp->key < node->key)
			tmp = tmp->pright;
		else
			tmp = tmp->pleft;
	}
	node->parent = tmpPrev;
	if (tmpPrev->key <= node->key)
		tmpPrev->pright = node;
	else
		tmpPrev->pleft = node;
}

Node* BinSearchTree::pull(float key)
{
	Node *x = 0;
	Node *y = 0;
	Node *z = search(key);

	if ((z->pleft) && (z->pright))
		y = searchNext(z);
	else
		y = z;
	if (y->pleft)
		x = y->pleft;
	else
		x = y->pright;
	if (x)
		x->parent = y->parent;
	if (y->parent)
		if (y == y->parent->pleft)
			y->parent->pleft = x;
		else
			y->parent->pright = x;
	if (y != z)
		z->key = y->key;
	return y;
}

void BinSearchTree::del(float key)
{
	delete pull(key);
}

int BinSearchTree::isEmpty() const
{
	if (root)
		return 0;
	else
		return 1;
}