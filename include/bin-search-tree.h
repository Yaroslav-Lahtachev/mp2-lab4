#pragma once
#include <cfloat>

class Node
{
public:
	float key;
	Node* pleft;
	Node* pright;
	Node* parent;
	void* data;
};

class BinSearchTree 
{
protected:
	Node* root;
public:
	BinSearchTree();
	~BinSearchTree();
		
	Node* search(float key);
	Node* searchPrev(Node *node);
	Node* searchNext(Node *node);
	Node* searchMin(Node *node = 0);
	Node* searchMax(Node *node = 0);
	
	void DelNode(Node *node);
	virtual void add(Node *&node);
	virtual void del(float key);
	virtual Node* pull(float key);

	int isEmpty() const;
};