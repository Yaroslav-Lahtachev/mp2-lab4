#pragma once
#include "bin-search-tree.h"


class AVLNode : public Node {
protected:
	char balance;
public:
	char getBalance() const;
	void setBalance(const char balance);
};

class AVLTree : public BinSearchTree {
public:
	AVLTree() {};
	virtual ~AVLTree() {};

	virtual void add(AVLNode *&node);
	virtual void del(float key);
	virtual void del(Node* node);
	virtual Node* pull(float key);
	virtual Node* pull(Node* node);
	int rotateRight(AVLNode *&node);
	int rotateLeft(AVLNode *&node);
	int DRotateRight(AVLNode *&node);
	int DRotateLeft(AVLNode *&node);
	int balanceDetection(AVLNode *node, int &dep);
	int height(AVLNode *node);
	int needBalance(AVLNode *&node);
	void ins(AVLNode *&localRoot, AVLNode *&node);
	Node* remuve(AVLNode *&localRoot, float key);
};